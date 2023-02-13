/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:39:32 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/13 14:22:28 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <sys/time.h>


/*
This function is used to render the background of the map.
It's called by render_main. and it's a loop called by mlx_loop_hook.
 */

void	render_bg(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if ((data->map[j][i] >= '1' && data->map[j][i] <= 'B') || data->map[j][i] == 'L')
				display_img(data, data->image.img_wall, i, j);
			if ((data->map[j][i] >= 'X' && data->map[j][i] < 'a'))
				display_img(data, data->image.img_wall_break, i, j);
			if ((data->map[j][i] >= '!' && data->map[j][i] <= '0'))
				display_img(data, data->image.img_floor, i, j);
			i++;

		}
		j++;
	}
}

/*
This function is used to render the collectibles, the player and the exit.
it's called by render_main which is a loop called by mlx_loop_hook.
We have to use a counter to make the animation of the player. The counter is
incremented by 1 each time the function is called. When the counter is equal to
120, it's reset to 0. The counter is used to know which image of the player we
have to display.
 */

void	render_other(t_data *data)
{
	int	i;
	int	j;

	data->counter = (data->counter + 1) % 120;
	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == data->content.collectible)
				render_collec(data, i, j);
			if (data->map[j][i] == data->content.player)
			{
				data->coord_move.x = i * data->image.img_width;
				data->coord_move.y = j * data->image.img_height;
				render_player(data, i, j);
			}
			if (data->map[j][i] == data->content.exit)
				render_exit(data, i, j);
			i++;
		}
		j++;
	}
}

/*
This function calls the two functions above and is called by mlx_loop_hook
 */

// int	render_main(t_data *data, int force)
// {
// 	static double sus;
// 	struct timeval	tv;
// 	double passus;

// 	passus = gettimeofday(&tv, NULL);
// 	passus = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

// 	if (((passus - sus)/1000) > (1./240.) || force)
// 	{
// 		// printf("%f \n", (passus - sus) / 1000);
// 		sus = passus;
// 		render_bg(data);
// 		render_other(data);
// 	}
// 	return (0);
// }

void	ft_create_new_image(t_data *data)
{
	data->image_new = mlx_new_image(data->mlx, data->size_x, data->size_y);
	if (data->image_new == NULL)
	{
		ft_putstr_fd("Error	: mlx_new_image failed	", 2);
		exit(1);
	}
	data->image_new_addr = mlx_get_data_addr(data->image_new, &data->bits_per_pixel, &data->line_length, &data->endian);
	if (data->image_new_addr == NULL)
	{
		ft_putstr_fd("Error	: mlx_get_data_addr failed	", 2);
		exit(1);
	}
}

void ft_put_image(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->image_new_addr + ((y * data->line_length) + (x * (data->bits_per_pixel / 8)));
	*(int *)pixel = color;
}

void render_stock(t_data *data)
{
	int i = 0;
	int j = 0;
	int	color = 0x5e5e5e;
	while (i < data->size_y)
	{
		j = 0;
		while (j < data->size_x)
		{
			//put image to window of green pixel
			ft_put_image(data, j, i, color);
			j++;
		}
		i++;
	}
}

int	render_main(t_data *data)
{
	render_bg(data);
	render_other(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image_new, 0, data->size_y);
	put_text(data);
	return (0);
}

/*
This function is used to create the window and to call the functions above.
If the window is not created, it will stop the program and display an error.
If the window is created, it will call the functions above. And init the
variables used in the functions above.
 */

void	window_utils(t_data *data)
{
	data->size_x = data->width * data->image.img_width;
	data->size_y = data->height * data->image.img_height;
	// ft_printf("size_x = %d\n", data->size_x);
	// ft_printf("size_y = %d\n", data->size_y);
	// ft_printf("Bande noire = %d\n", data->size_y + 48);
	data->win = mlx_new_window(data->mlx, \
		(data->size_x), \
		(data->size_y + 48), "So long");
	if (data->win == NULL)
	{
		ft_error("Error\nWindow not created\n");
		ft_stop(data, FAIL);
		return ;
	}
	data->counter = 0;
	data->anim = 0;

	ft_create_new_image(data);
	render_stock(data);
	ft_count_collect(data);
	mlx_loop_hook(data->mlx, &render_main, data);
	mlx_hook(data->win, 2, 1L << 0, move_key, data);
	mlx_hook(data->win, 17, 1L << 17, cross_close, data);
	mlx_key_hook(data->win, esc_close, data);
	mlx_loop(data->mlx);
	ft_stop(data, SUCCESS);
}

/*
This function is used to display the images on the window.
It's called by render_bg and render_other.
 */

void	display_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, \
		data->image.img_width * x, data->image.img_height * y);
}

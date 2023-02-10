/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:28:17 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/09 18:50:00 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Function to move a player. I use dy and dx which is equal to 1 / -1 / or 0
depending on the direction I want to move. */

// void	ft_move_all(t_data *data, int dy, int dx)
// {
// 	int	pos_x;
// 	int	pos_y;
// 	int	i;
// 	int	j;

// 	// print all map to see if the player is moving
// 	j = 0;
// 	while (data->map[j] != NULL)
// 	{
// 		i = 0;
// 		while (data->map[j][i] != '\0')
// 		{
// 			ft_printf("%c", data->map[j][i]);
// 			i++;
// 		}
// 		ft_printf("\n");
// 		j++;
// 	}
// 	ft_printf("\n");

// 	pos_x = data->coord_move.x / data->image.img_height;
// 	pos_y = data->coord_move.y / data->image.img_width;
// 	if (data->map[pos_y + dy][pos_x + dx] != data->content.wall)
// 	{
// 		if (!(data->map[pos_y + dy][pos_x + dx] == data->content.exit))
// 		{
// 			data->map[pos_y + dy][pos_x + dx] = data->content.player;
// 			data->map[pos_y][pos_x] = data->content.empty;
// 			data->count++;
// 			ft_printf("count : %d\n", data->count);
// 		}
// 		else
// 		{
// 			if (ft_count_collect(data) == 0)
// 			{
// 				data->count++;
// 				ft_printf("count : %d\n", data->count);
// 				ft_printf("GG vous avez gagne en %d coups\n", data->count);
// 				if (data->nb_map == 10)
// 					ft_stop(data, SUCCESS);
// 				else
// 					ft_stop(data, NEXT);
// 			}
// 		}
// 	}
// }

void	ft_move_all(t_data *data, int dy, int dx)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->coord_move.x / data->image.img_height;
	pos_y = data->coord_move.y / data->image.img_width;
	ft_count_collect(data);
	if (data->content.count_collectible == 1)
	{
		data->nb_take_collect = 0;
		ft_printf("nb_take_collect : %d\n", data->nb_take_collect);
	}
	// printf("pos_x : %d, width: %d\n", pos_x, data->width);
	// printf("pos_y : %d, widtd: %d\n", pos_y, data->height);
	if (pos_x + dx < 0 || pos_y + dy < 0 || pos_x + dx >= data->width || pos_y + dy >= data->height)
		return ;
	if (!(data->map[pos_y + dy][pos_x + dx] >= '1' && data->map[pos_y + dy][pos_x + dx] <= 'B'))
	{
		if ((data->map[pos_y + dy][pos_x + dx] != data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.empty;
			data->map[pos_y + dy][pos_x + dx] = data->content.player;
			data->count++;
			data->total_count_move++;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			// ft_count_collect(data);

			if (data->remaning_collect == 0)
			{
				data->count++;
				data->total_count_move++;
				ft_printf("count : %d\n", data->count);
				ft_printf("GG vous avez gagne en %d coups\n", data->count);
				if (data->nb_map == 1)
				{
					ft_printf("TOTAL COUNT MOVE : %d\n", data->total_count_move);
					ft_printf("TOTAL COUNT COLLECT : %d\n", data->total_count_collect);
					ft_printf("TOTAL COUNT OTHER : %d\n", data->total_count_other);
					ft_stop(data, SUCCESS);
				}
				else
					ft_stop(data, NEXT);
			}
		}


	}
}

/* Function to display the number of movements on the Window */

void	put_text(t_data *data)
{
	char	*text;
	char	*number;
	char	*nb_collectible;
	char	*text_collectible;
	char	*text_other;
	char	*nb_other;

	number = ft_itoa(data->count);
	nb_collectible = ft_itoa(data->remaning_collect);
	text_collectible = ft_strjoin("Collectible restant ", nb_collectible);
	text = ft_strjoin("Move: ", number);
	nb_other = NULL;
	text_other = NULL;
	if (data->content.total_other > 0)
	{
		nb_other = ft_itoa(data->content.count_other);
		text_other = ft_strjoin("Secret: ", nb_other);
		mlx_string_put(data->mlx, data->win, 5, data->size_y + 10, 0xffffff, text_other);
	}
	else
	{
		(void)nb_other;
		(void)text_other;
	}
	mlx_string_put(data->mlx, data->win, 5, data->size_y + 25, 0xffffff, text_collectible);
	mlx_string_put(data->mlx, data->win, 5, data->size_y + 40, 0xffffff, text);
	free(text_collectible);
	free(nb_collectible);
	free(text_other);
	free(nb_other);
	free(text);
	free(number);
}

// void	put_text(t_data *data)
// {
// 	char	*final_text;
// 	char	*nb_other;
// 	char	*total_other;
// 	char	*text;

// 	total_other = ft_itoa(data->content.count_other);
// 	text = ft_strjoin("Collectible: ", nb_other);
// 	final_text = ft_strjoin(text, " / ");

// 	mlx_string_put(data->mlx, data->win, 5, 20, 0xffffff, final_text);
// 	free(text);
// 	free(nb_other);
// }

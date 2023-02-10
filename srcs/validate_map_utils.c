/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/30 14:01:09 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_pos(t_pos *pos, const int x, const int y)
{
	pos->x = x;
	pos->y = y;
}

void	init_deplacement(int deplacements[4][2])
{
	int			i;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	i = 0;
	while (i < 4)
	{
		deplacements[i][0] = dx[i];
		deplacements[i][1] = dy[i];
		i++;
	}
}

void	alloc_array(t_data *data)
{
	int	i;

	i = 0;
	data->queue.array = malloc(sizeof(t_pos) * data->height * data->width);
	if (data->queue.array == NULL)
	{
		ft_error("Error\nMalloc failed\n");
		ft_clean_map(data);
		mlx_destroy_display(data->mlx);
		ft_free_array(data);
		free(data->mlx);
		exit(1);
	}
	while (i < data->height * data->width)
	{
		data->queue.array[i].x = 0;
		data->queue.array[i].y = 0;
		i++;
	}
}

void	alloc_visits(t_data *data)
{
	int	i;

	i = 0;
	data->near.visits = malloc(sizeof(bool *) * (data->height + 1));
	if (data->near.visits == NULL)
	{
		ft_error("Error\nMalloc failed\n");
		ft_check_malloc_visit(data);
		exit(1);
	}
	while (i < data->height)
	{
		data->near.visits[i] = malloc(sizeof(bool) * (data->width));
		if (data->near.visits[i] == NULL)
		{
			ft_error("Error\nMalloc failed\n");
			ft_check_malloc_visit(data);
			ft_free_visits(data);
			free(data->mlx);
			exit(1);
		}
		i++;
	}
	data->near.visits[i] = NULL;
}

void	init_visits(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	alloc_visits(data);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->near.visits[i][j] = false;
			j++;
		}
		i++;
	}
}

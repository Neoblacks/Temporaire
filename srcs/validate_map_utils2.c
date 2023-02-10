/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:41:46 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/18 16:06:44 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_queue(t_data *data, t_pos *pos)
{
	data->queue.debut = 0;
	data->queue.fin = 1;
	data->queue.array[0] = *pos;
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->position.x = i;
				data->position.y = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_check_malloc_visit(t_data *data)
{
	if (data->queue.array == NULL)
	{
		ft_error("Error\nMalloc failed");
		ft_clean_map(data);
		mlx_destroy_display(data->mlx);
		ft_free_array(data);
		free(data->mlx);
		exit(1);
	}
}

int	ft_check_exit(t_data *data, int deplacements[4][2])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->map[data->position.x + deplacements[i][0]] \
			[data->position.y + deplacements[i][1]] == 'E')
			data->exit_found = 1;
		i++;
	}
	return (data->exit_found);
}

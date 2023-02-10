/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:49:22 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/09 11:31:54 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_visits(t_data *data)
{
	int	i;

	i = 0;
	while (data->near.visits[i])
	{
		free(data->near.visits[i]);
		i++;
	}
	free(data->near.visits);
}

void	ft_free_array(t_data *data)
{
	free(data->queue.array);
}

void	ft_stop(t_data *data, int code)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		ft_destroy_img(data);
		if (data->win != NULL)
			mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	if (data->near.visits != NULL)
		ft_free_visits(data);
	if (data->queue.array != NULL)
		ft_free_array(data);
	free(data->mlx);
	if (code == SUCCESS)
		exit(0);
	else if (code == NEXT)
		ft_next_map(data);
	else if (code == FAIL)
		exit(1);
}

void	*ft_clean_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		return (0);
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

int	ft_urgency(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		ft_destroy_img(data);
		mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(1);
}

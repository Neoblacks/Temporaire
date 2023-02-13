/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:50:09 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/10 17:01:37 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_next_map(t_data *data)
{
	char	*next_map_nb;
	char	*next_map;
	char	*nb_map;
	int		deplacement[4][2];

	data->nb_map = data->nb_map + 1;
	data->count = 0;
	ft_content(&(data->content));
	nb_map = ft_itoa(data->nb_map);
	next_map_nb = ft_strjoin("map/map_level", nb_map);
	next_map = ft_strjoin(next_map_nb, ".ber");
	map(next_map, data);
	free(next_map);
	free(next_map_nb);
	free(nb_map);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_error("Mlx init failed");
		exit(1);
	}
	ft_check_data_map(data, deplacement);
}

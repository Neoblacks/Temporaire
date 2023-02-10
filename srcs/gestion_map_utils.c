/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:59:37 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/01 12:02:54 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Function to count how many P, E, and C inside the map */

void	ft_check_nb_symbols(t_data *data)
{
	if ((data->content.count_collectible == 0 || \
		data->content.count_exit != 1 || data->content.count_player != 1) && \
		data->map != NULL)
	{
		ft_clean_map(data);
		ft_error("Error\nNeed 1 P, 1 Exit, and 1 Co\n");
		exit(1);
	}
}

void	ft_check_file_empty(int fd)
{
	char	buffer[1];
	int		ret;

	ret = read(fd, buffer, 1);
	if (ret == 0)
	{
		ft_error("Error\nEmpty file\n");
		close(fd);
		exit(1);
	}
	else if (ret == -1)
	{
		ft_error("Error\nto open file\n");
		close(fd);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:58:15 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/10 12:35:46 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if first and last columns are closed */

int	ft_check_column(char *map_line, char wall, t_data *data)
{
	int	i;
	(void)wall;

	i = 0;
	while (map_line[i] != '\0')
		i++;
	if ((!(map_line[0] >= '1' && map_line[0] <= 'B') || !(map_line[i - 1] >= '1' && map_line[i - 1] <= 'B')) && (!(map_line[0] >= 'X' && map_line[0] < 'a') || !(map_line[i - 1] >= 'X' && map_line[i - 1] < 'a')))
	{
		ft_error("Error\nMap column are not close\n");
		return (FAIL);
	}
	data->width = i;
	return (EXIT_SUCCESS);
}

/* Checks if first and last lines are closed */

int	ft_check_line(char *map_line, char wall)
{
	int	i;
	(void)wall;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (!(map_line[i] >= '1' && map_line[i] <= 'B') && !(map_line[i] >= 'X' && map_line[i] <= 'a'))
		{
			ft_error("Error\nMap line are not close\n");
			return (FAIL);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/* Checks if we don't have another symbol inside map file */

// int	ft_check_other(char *map_line, t_content *content)
// {
// 	int	i;

// 	i = 0;
// 	while (map_line[i] != '\0')
// 	{
// 		if (content->count_exit > 1 || content->count_player > 1)
// 		{
// 			ft_error("Error\nBad number of exit or player\n");
// 			return (FAIL);
// 		}
// 		if (map_line[i] != content->wall && map_line[i] != content->player && map_line[i] != content->exit && map_line[i] != content->collectible && map_line[i] != '0')
// 		{
// 			ft_error("Error\nBad symbol in map");
// 			return (FAIL);
// 		}
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

int	ft_check_other(char *map_line, t_content *content)
{
	int	i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (content->count_exit > 1 || content->count_player > 1)
		{
			ft_error("Error\nBad number of exit or player\n");
			return (FAIL);
		}
		if (map_line[i] != content->player && map_line[i] != content->exit && map_line[i] != content->collectible && !(map_line[i] >= '!' && map_line[i] <= '0')  && !(map_line[i] >= '1' && map_line[i] <= 'B') && !(map_line[i] >= 'X' && map_line[i] <= 'a') && map_line[i] != content->other)
		{
			ft_error("Error\nBad symbol in map");
			return (FAIL);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

/* Checks if there is only one exit and one player and
	checks if there is at least one collectible */

void	ft_check_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;

	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.collectible)
				data->content.count_collectible += 1;
			if (data->map[i][j] == data->content.player)
				data->content.count_player += 1;
			if (data->map[i][j] == data->content.exit)
				data->content.count_exit += 1;
			if (data->map[i][j] == data->content.other)
				data->content.total_other += 1;
			j++;
		}
		j = 0;
		i++;
	}
}

/* Checks if map is a rectangle */

int	ft_check_format(char **map)
{
	int	width;
	int	height;
	int	count_width;

	width = 0;
	height = 0;
	count_width = 0;
	if (map[0] == NULL)
		return (ft_error("Error\nMap is empty\n"), FAIL);
	while (map[0][count_width] != '\0')
		count_width++;
	while (map[height] != NULL)
	{
		while (map[height][width] != '\0')
			width++;
		if (width != count_width)
		{
			ft_error("Error\nMap is not a rectangle\n");
			return (FAIL);
		}
		width = 0;
		height++;
	}
	return (EXIT_SUCCESS);
}

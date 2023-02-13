/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:12 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/13 15:37:52 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
This function is used to count the number of collectibles in the map. It will
return the number of collectibles in the map.
 */

void	ft_count_collect(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	data->remaning_collect = 0;
	data->content.remaning_other = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] == data->content.collectible)
			{
				data->remaning_collect++;
			}
			if (data->map[j][i] == data->content.other)
				data->content.remaning_other++;
			i++;
		}
		j++;
	}
}

/*
This function is used to make a research in a string. It will return EXIT_SUCCESS
if the string is found in the string given in parameter, and FAIL if not.
 */

int	ft_strstr(const char *str, char *comp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && comp[j] == '\0')
		return (EXIT_SUCCESS);
	while (str[i] != '\0')
	{
		while (str[i + j] == comp[j] && str[i + j] != '\0' && comp[j] != '\0')
			j++;
		if (comp[j] == '\0' && str[i + j] == '\0')
			return (EXIT_SUCCESS);
		else
			j = 0;
		i++;
	}
	return (FAIL);
}

/*
This function is used to check the result of map function. If the map is
valid it will call check_find_collect_exit and ft_texture. If the map is
not valid it will call ft_urgency
*/

void	ft_check_data_map(t_data *data, int deplacements[4][2])
{
	if (data->map != NULL)
	{
		check_find_collect_exit(data, deplacements);
		ft_texture(data);
		window_utils(data);
	}
	else
		ft_urgency(data);
}

/*
This function is the main function. It start by checking if we have 2 args
(executable, and map). If the mlx init fails it returns an error to
protect a segfault, and calls ft_check_data_map */

// int	main(int argc, char **argv)
// {
// 	t_data	data;
// 	int		deplacements[4][2];

// 	if (argc != 1)
// 	{
// 		ft_error("Error\nWe don't need to put a map\n");
// 		exit(1);
// 	}
// 	else
// 	{
// 		data.count = 0;
// 		ft_content(&(data.content));
// 		map(argv, &(data));
// 		data.mlx = mlx_init();
// 		if (!data.mlx)
// 		{
// 			ft_error("Error!\nMlx_init failed\n");
// 			exit(1);
// 		}
// 		ft_check_data_map(&data, deplacements);
// 	}
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data data;
	int deplacement[4][2];
	char	*first_map;
	(void)argv;

	if (argc != 1)
	{
		ft_error("Error\nWe don't need to put a map\n");
		exit(1);
	}
	else
	{
		data.total_count_collect = 0; //NEED TO CALL THIS INITIALIZATION
		data.nb_map = 1;
		data.count = 0;
		data.nb_take_collect = 0;
		data.nb_total_take_collect = 0;
		data.nb_total_take_other = 0;
		ft_content(&(data.content));
		first_map = "map/map_level1.ber";
		map(first_map, &(data));
		data.mlx = mlx_init();
		if (!data.mlx)
		{
			ft_error("Error!\nMlx_init failed\n");
			exit(1);
		}
		ft_check_data_map(&data, deplacement);
	}
	return (0);
}

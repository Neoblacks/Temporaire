/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:50:59 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/09 18:30:03 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Puts data of map inside a variable to prepare a comparison for Parsing */

void	ft_content(t_content *content)
{
	content->wall = '1';
	content->exit = 'E';
	content->empty = '0';
	content->player = 'P';
	content->collectible = 'C';
	content->other = 'L';
	content->count_collectible = 0;
	content->count_player = 0;
	content->count_exit = 0;
	content->total_other = 0;
}

/* Puts xpm file inside variable and puts this data inside
	mlx_xpm_file_to_image to convert this to pointer */

void	ft_texture(t_data *data)
{
	data->image.img_height = 32;
	data->image.img_width = 32;
	data->image.wall = "xpm/wall.xpm";
	data->image.wall_break = "xpm/wall3.xpm";
	data->image.floor = "xpm/floor.xpm";
	data->image.exit_activate = "xpm/exit_activate.xpm";
	data->image.exit_desactivate = "xpm/exit_desactivate.xpm";
	ft_texture_player(data);
	ft_texture_collec(data);
	data->image.img_exit_activate = mlx_xpm_file_to_image(data->mlx, \
		data->image.exit_activate, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_exit_desactivate = mlx_xpm_file_to_image(data->mlx, \
		data->image.exit_desactivate, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_wall = mlx_xpm_file_to_image(data->mlx, data->image.wall, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_floor = mlx_xpm_file_to_image(data->mlx, data->image.floor, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_wall_break = mlx_xpm_file_to_image(data->mlx, \
		data->image.wall_break, \
		&(data->image.img_height), &(data->image.img_width));
	ft_check_file(data);
}

void	ft_texture_player(t_data *data)
{
	data->image.player_idle1 = "xpm/player_idle1.xpm";
	data->image.player_idle2 = "xpm/player_idle2.xpm";
	data->image.player_idle3 = "xpm/player_idle3.xpm";
	data->image.player_idle4 = "xpm/player_idle4.xpm";
	data->image.img_player_idle1 = mlx_xpm_file_to_image(data->mlx, \
		data->image.player_idle1, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_player_idle2 = mlx_xpm_file_to_image(data->mlx, \
		data->image.player_idle2, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_player_idle3 = mlx_xpm_file_to_image(data->mlx, \
		data->image.player_idle3, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_player_idle4 = mlx_xpm_file_to_image(data->mlx, \
		data->image.player_idle4, \
		&(data->image.img_height), &(data->image.img_width));
}

void	ft_texture_collec(t_data *data)
{
	data->image.collectible_1 = "xpm/collect_1.xpm";
	data->image.collectible_2 = "xpm/collect_2.xpm";
	data->image.collectible_3 = "xpm/collect_3.xpm";
	data->image.collectible_4 = "xpm/collect_4.xpm";
	data->image.img_collectible_1 = mlx_xpm_file_to_image(data->mlx, \
		data->image.collectible_1, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_collectible_2 = mlx_xpm_file_to_image(data->mlx, \
		data->image.collectible_2, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_collectible_3 = mlx_xpm_file_to_image(data->mlx, \
		data->image.collectible_3, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_collectible_4 = mlx_xpm_file_to_image(data->mlx, \
		data->image.collectible_4, \
		&(data->image.img_height), &(data->image.img_width));
}

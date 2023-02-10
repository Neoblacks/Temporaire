/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:26:24 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/01 12:00:24 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image.img_wall);
	mlx_destroy_image(data->mlx, data->image.img_floor);
	mlx_destroy_image(data->mlx, data->image.img_player_idle1);
	mlx_destroy_image(data->mlx, data->image.img_player_idle2);
	mlx_destroy_image(data->mlx, data->image.img_player_idle3);
	mlx_destroy_image(data->mlx, data->image.img_player_idle4);
	mlx_destroy_image(data->mlx, data->image.img_collectible_1);
	mlx_destroy_image(data->mlx, data->image.img_collectible_2);
	mlx_destroy_image(data->mlx, data->image.img_collectible_3);
	mlx_destroy_image(data->mlx, data->image.img_collectible_4);
	mlx_destroy_image(data->mlx, data->image.img_exit_activate);
	mlx_destroy_image(data->mlx, data->image.img_exit_desactivate);
}

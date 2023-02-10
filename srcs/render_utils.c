/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:43:03 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/09 18:40:16 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
This function is used to make a render of the collectible. It will display the
collectible sprite depending on the counter.
 */

void	render_collec(t_data *data, int i, int j)
{
	if (data->counter < 30)
		display_img(data, data->image.img_collectible_1, i, j);
	else if (data->counter < 60)
		display_img(data, data->image.img_collectible_2, i, j);
	else if (data->counter < 90)
		display_img(data, data->image.img_collectible_3, i, j);
	else if (data->counter < 120)
		display_img(data, data->image.img_collectible_4, i, j);
}

/*
This function is used to make a render of the player. It will display the player
sprite depending on the counter.
 */

void	render_player(t_data *data, int i, int j)
{
	if (data->counter < 30)
		display_img(data, data->image.img_player_idle1, i, j);
	else if (data->counter < 60)
		display_img(data, data->image.img_player_idle2, i, j);
	else if (data->counter < 90)
		display_img(data, data->image.img_player_idle3, i, j);
	else if (data->counter < 120)
		display_img(data, data->image.img_player_idle4, i, j);
}

/* This function is used to make a render of the exit. It will display the exit
sprite depending of the number of collectible. */

void	render_exit(t_data *data, int i, int j)
{
	// ft_count_collect(data);
	if (data->remaning_collect == 0)
		display_img(data, data->image.img_exit_desactivate, i, j);
	else
		display_img(data, data->image.img_exit_activate, i, j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:58 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/09 15:20:49 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Closes window with Escape key */

int	esc_close(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		ft_stop(data, SUCCESS);
	return (0);
}

/* Closes window with red cross */

int	cross_close(t_data *data)
{
	ft_stop(data, SUCCESS);
	return (0);
}

/* Moves player with W, A, S, D keys and directionnal Arrows */

int	move_key(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		ft_move_all(data, -1, 0);
	if (keycode == S_KEY || keycode == DOWN_KEY)
		ft_move_all(data, 1, 0);
	if (keycode == A_KEY || keycode == LEFT_KEY)
		ft_move_all(data, 0, -1);
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		ft_move_all(data, 0, 1);
	if (keycode == F_KEY)
		ft_move_all(data, 1, 1);
	if (keycode == G_KEY)
		ft_move_all(data, -1, -1);
	if (keycode == H_KEY)
		ft_move_all(data, -1, 1);
	if (keycode == J_KEY)
		ft_move_all(data, 1, -1);
	render_main(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:04:13 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/09 11:13:06 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pt1, const void *pt2, size_t size)
{
	unsigned long	position;
	int				delta;

	position = 0;
	while (position < size)
	{
		position++;
		delta = *(unsigned char *)pt1++ - *(unsigned char *)pt2++;
		if (delta)
			return (delta);
	}
	return (0);
}

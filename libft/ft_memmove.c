/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:54:10 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/12 18:49:18 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (s < d)
	{
		i = 0;
		while (i < n)
		{
			d[n - i - 1] = s[n - i - 1];
			++i;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

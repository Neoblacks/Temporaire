/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:51:54 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/12 19:26:42 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memblock, int charset, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (void *)memblock;
	while (i < size)
	{
		if (str[i] == (char)charset)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

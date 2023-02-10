/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:42 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/12 12:32:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnjoin_gnl(char const *s1, char const *s2, size_t n)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	if (s1 != NULL)
		len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	if (len2 > n)
		len2 = n;
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy_gnl(str, s1, len1 + 1);
	ft_strlcpy_gnl(str + len1, s2, len2 + 1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

void	ft_bzero_gnl(void *s, size_t nb)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < nb)
	{
		str[i] = 0;
		i++;
	}
}

size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:44:57 by amugnier          #+#    #+#             */
/*   Updated: 2022/11/12 18:59:20 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = len;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (0);
		str[0] = '\0';
		return (str);
	}
	if (ft_strlen(s + start) < len)
		i = ft_strlen(s + start);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), i + 1);
	return (str);
}

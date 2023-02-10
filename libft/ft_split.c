/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:45:41 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 12:18:02 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_sep(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

int	count_words(const char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_sep(str[i + 1], sep) == 1 && char_is_sep(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

void	ft_word(char *dest, const char *from, char sep)
{
	int	i;

	i = 0;
	while (char_is_sep(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

int	write_split(char **split, const char *str, char sep)
{
	size_t	j;
	size_t	word;

	word = 0;
	while (*str != '\0')
	{
		if (char_is_sep(*str, sep) == 1)
			++str;
		else
		{
			j = 0;
			while (char_is_sep(str[j], sep) == 0)
				++j;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!split[word])
				return (EXIT_FAILURE);
			ft_word(split[word], str, sep);
			str += j;
			word++;
		}
	}
	return (EXIT_SUCCESS);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	if (write_split(res, s, c) == EXIT_FAILURE)
	{
		while (words > 0)
			free(res[--words]);
		free(res);
		res = NULL;
	}
	return (res);
}

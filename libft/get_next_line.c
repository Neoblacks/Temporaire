/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:57:08 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/15 11:04:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_gnl(char *dest, char *src, ssize_t n)
{
	char	*new;

	new = NULL;
	if (n != -1)
	{
		new = ft_strnjoin_gnl(dest, src, n);
		free(dest);
	}
	return (new);
}

void	ft_cut_gnl(char *buffer, char *rest)
{
	ssize_t	len;

	len = ft_get_index_gnl(buffer, '\n');
	if (len >= 0)
		ft_strlcpy_gnl(rest, buffer + len + 1, BUFFER_SIZE);
}

ssize_t	ft_get_index_gnl(char *str, char searched_char)
{
	ssize_t	i;

	i = 0;
	while (str[i] != searched_char && str[i] != '\0')
		i++;
	if (str[i] != searched_char)
		return (-1);
	return (i);
}

char	*readfile_gnl(int fd, char *line, char *rest)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes;

	ft_bzero_gnl(buffer, BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0 && ft_strchr_gnl(buffer, '\n') == NULL)
	{
		line = ft_add_gnl(line, buffer, BUFFER_SIZE);
		ft_bzero_gnl(buffer, BUFFER_SIZE + 1);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr_gnl(buffer, '\n') != NULL)
	{
		line = ft_add_gnl(line, buffer, ft_get_index_gnl(buffer, '\n') + 1);
		ft_cut_gnl(buffer, rest);
	}
	if (bytes == 0 && line == NULL)
		return (NULL);
	if (bytes == 0 && line[0] != '\0')
	{
		ft_bzero_gnl(rest, BUFFER_SIZE);
		return (line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		rest[FOPEN_MAX][BUFFER_SIZE + 1] = {0};
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd > FOPEN_MAX)
		return (NULL);
	if (ft_strchr_gnl(rest[fd], '\n') != NULL)
	{
		line = ft_add_gnl(line, rest[fd], ft_get_index_gnl(rest[fd], '\n') + 1);
		ft_cut_gnl(rest[fd], rest[fd]);
	}
	else
	{
		if (*rest[fd] != '\0')
			line = ft_add_gnl(line, rest[fd], BUFFER_SIZE);
		line = readfile_gnl(fd, line, rest[fd]);
	}
	return (line);
}

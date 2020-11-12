/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:03:25 by htinisha          #+#    #+#             */
/*   Updated: 2020/08/03 04:45:26 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	linelen(char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

int		work_with_re(char **buffer, char **re, char **line)
{
	if (!(*line = ft_strtosup(*buffer, linelen(*buffer))))
		return (-1);
	*re = ft_strtosup(*buffer + linelen(*buffer) + 1, ft_strlen(*buffer));
	if (!re)
		return (-1);
	free(*buffer);
	return (1);
}

int		work_with_bf(char **buffer, int fd, int a)
{
	char		*front;
	char		*end;

	if (!(front = ft_strtosup(*buffer, ft_strlen(*buffer))))
		return (-1);
	free(*buffer);
	if (!(end = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	read(fd, end, BUFFER_SIZE);
	if (ft_strlen(end) < (size_t)BUFFER_SIZE && !(ft_strchr(end, '\n')))
		a = 0;
	if (!(*buffer = ft_strjoin(front, end)))
		return (-1);
	free(front);
	free(end);
	return (a);
}

int		part_2(char *buffer, char **line, char **re, int fd)
{
	int			a;

	a = 2;
	while (a != 1 && a != 0)
	{
		if (ft_strchr(buffer, '\n'))
			a = work_with_re(&buffer, &*re, &*line);
		else
			a = work_with_bf(&buffer, fd, a);
		if (a == -1)
			return (-1);
	}
	if (a == 0)
	{
		if (!(*line = ft_strtosup(buffer, ft_strlen(buffer))))
			return (-1);
		free(buffer);
	}
	return (a);
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*re[1024];

	if (line == NULL || fd > 1024 || BUFFER_SIZE < 1 || read(fd, re, 0) < 0)
		return (-1);
	if (re[fd])
	{
		if (!(buffer = ft_strtosup(re[fd], ft_strlen(re[fd]))))
			return (-1);
		free(re[fd]);
		re[fd] = NULL;
	}
	else
	{
		if (!(buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
			return (-1);
		read(fd, buffer, BUFFER_SIZE);
	}
	return (part_2(buffer, &*line, &re[fd], fd));
}

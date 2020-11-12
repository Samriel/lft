/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 21:03:21 by htinisha          #+#    #+#             */
/*   Updated: 2020/11/12 13:49:43 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

void	*ft_calloc(size_t n, size_t b);
int		get_next_line(int fd, char **line);
char	*ft_strtosup(char const *s, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif

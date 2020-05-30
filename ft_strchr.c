/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 03:42:28 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/28 22:03:04 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int c)
{
	char	*s;

	s = (char *)string;
	while (*s != c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return (s);
}

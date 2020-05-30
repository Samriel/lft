/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:55:01 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/28 22:14:29 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;
	char	*find;

	len = ft_strlen(str);
	find = (char *)(str + len);
	len += 1;
	while (len--)
	{
		if (*find == (unsigned char)ch)
			return (find);
		find--;
	}
	return (NULL);
}

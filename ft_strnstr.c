/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:54:54 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/28 22:01:39 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_td;

	len_td = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && len-- >= len_td)
	{
		if (*big == *little && ft_memcmp(big, little, len_td) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htinisha <htinisha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:20:34 by htinisha          #+#    #+#             */
/*   Updated: 2020/05/28 22:23:53 by htinisha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(long int n)
{
	int		len;

	if (n == -2147483648)
		return (11);
	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int x)
{
	char		*s;
	size_t		len;
	long int	n;

	n = x;
	if (x == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 1 + ft_intlen(n);
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len - 1] = '\0';
	while (n)
	{
		len--;
		s[len - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

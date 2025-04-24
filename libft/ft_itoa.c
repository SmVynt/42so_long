/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:21:35 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/11 19:18:41 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numsize(int n)
{
	size_t	len;
	long	a;

	len = 1;
	a = n;
	if (n < 0)
	{
		len++;
		a *= -1;
	}
	while (a >= 10)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	long	a;

	len = ft_numsize(n);
	a = n;
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	ret[0] = '0';
	if (n < 0)
	{
		a = -a;
		ret[0] = '-';
	}
	while (a != 0)
	{
		len--;
		ret[len] = (a % 10) + '0';
		a = a / 10;
	}
	return (ret);
}

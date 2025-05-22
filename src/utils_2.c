/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/22 23:28:03 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len])
		len++;
	if (size <= 0)
		return (len);
	i = 0;
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i != n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}

t_vec	mk_vec(int x, int y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

int	ft_lerp_int(int a, int b, float t)
{
	float	d;

	d = t * (float)(b - a);
	if (d > -1.0f && d < 0.0f)
		return (a - 1);
	if (d > 0.0f && d < 1.0f)
		return (a + 1);
	return (a + (int)d);
}

float	ft_lerp(float a, float b, float t)
{
	return (a + (b - a) * t);
}

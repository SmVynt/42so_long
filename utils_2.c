/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/12 23:49:39 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *a)
{
	size_t	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
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

int	ft_lerp(int a, int b, int t)
{
	float	d;

	d = (float)(b - a) / (float)t;
	if (d > -1.0f && d < 0.0f)
		d = -1.0f;
	if (d < 1.0f && d > 0.0f)
		d = 1.0f;
	return (a + (int)d);
}

int	ft_tol(int a, int b)
{
	int	tolerance;

	tolerance = 1;
	if (a - b <= tolerance && a - b >= -tolerance)
		return (1);
	return (0);
}

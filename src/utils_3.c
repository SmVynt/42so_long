/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/20 19:58:00 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_random(int min, int max)
{
	static unsigned int	magic;
	int					range;

	magic = (157 * magic + 2543) % 124448785;
	range = max - min + 1;
	return (min + (magic % range));
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_dir(int a, int b)
{
	if (a < b)
		return (-1);
	if (a > b)
		return (1);
	return (0);
}

int	ft_tol(int a, int b)
{
	int	tolerance;

	tolerance = 1;
	if (a - b <= tolerance && a - b >= -tolerance)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/01 17:55:53 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Make a color from its RGBA components.
 */
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/**
 * Returns the RED channel of a color.
 */
int	get_r(int rgba)
{
	return ((rgba >> 24) & 0xFF);
}

/**
 * Returns the GREEN channel of a color.
 */
int	get_g(int rgba)
{
	return ((rgba >> 16) & 0xFF);
}

/**
 * Returns the BLUE channel of a color.
 */
int	get_b(int rgba)
{
	return ((rgba >> 8) & 0xFF);
}

/**
 * Returns the ALPHA channel of a color.
 */
int	get_a(int rgba)
{
	return (rgba & 0xFF);
}
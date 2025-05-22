/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/09 02:35:45 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_copy_pixel(char *dst, char *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
}

// static void	ft_copy_pixel_ca(int x, int y, char *dst, char *src)
// {
// 	unsigned char	r;
// 	unsigned char	g;
// 	unsigned char	b;

// 	r = (unsigned char)src[0];
// 	g = (unsigned char)src[1];
// 	b = (unsigned char)src[2];
// 	r = r + ((x % 3 == 0) * 2 - 1) * r * (255 - r) / 255;
// 	g = g + ((x % 3 == 1) * 2 - 1) * g * (255 - g) / 255;
// 	b = b + ((x % 3 == 2) * 2 - 1) * b * (255 - b) / 255;
// 	(void)y;
// 	dst[0] = (char)r;
// 	dst[1] = (char)g;
// 	dst[2] = (char)b;
// 	dst[3] = src[3];
// }

static void	ft_copy_pixel_ca(int x, int y, char *dst, char *src)
{
	int		xr;
	int		yr;

	xr = x % 3;
	yr = y % 3;
	dst[0] = src[0] * (xr != 0);
	dst[1] = src[1] * (yr != 0);
	dst[2] = src[2] * (xr != 1);
	dst[3] = src[3];
}

/*
** Scales the source image to fit the destination image.
*/
void	ft_scale_image(t_texture *src, t_texture *dst)
{
	int		x;
	int		y;
	char	*src_ptr;
	char	*dst_ptr;

	src_ptr = get_img_data(src->src).data;
	dst_ptr = get_img_data(dst->src).data;
	x = 0;
	while (x < dst->w)
	{
		y = 0;
		while (y < dst->h)
		{
			ft_copy_pixel(&dst_ptr[(y * dst->w * 4 + x * 4)],
				&src_ptr[(y / SCALE * src->w * 4 + x / SCALE * 4)]);
			y++;
		}
		x++;
	}
}

/*
** Scales the source image to fit the destination image.
*/
void	ft_scale_image_ca(t_texture *src, t_texture *dst)
{
	int		x;
	int		y;
	char	*src_ptr;
	char	*dst_ptr;

	src_ptr = get_img_data(src->src).data;
	dst_ptr = get_img_data(dst->src).data;
	x = 0;
	while (x < dst->w)
	{
		y = 0;
		while (y < dst->h)
		{
			ft_copy_pixel_ca(x, y, &dst_ptr[(y * dst->w * 4 + x * 4)],
				&src_ptr[(y / SCALE * src->w * 4 + x / SCALE * 4)]);
			y++;
		}
		x++;
	}
}

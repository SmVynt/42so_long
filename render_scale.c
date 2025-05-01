/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/01 21:39:46 by psmolin          ###   ########.fr       */
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
			ft_copy_pixel(&dst_ptr[(y * dst->w * 4 + x * 4)],
				&src_ptr[(y * src->w * 4 + x * 4) / SCALE]);
			y++;
		}
		x++;
	}
}

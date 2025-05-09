/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/09 02:26:38 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_imgdt	get_img_data(void *img)
{
	t_imgdt	img_data;

	img_data.data = mlx_get_data_addr(img, &img_data.bpp,
			&img_data.size_line, &img_data.endian);
	return (img_data);
}

void	ft_set_pixel(char *dst, int x, int y, int color)
{
	(void)x;
	(void)y;
	dst[0] = get_r(color);
	dst[1] = get_g(color);
	dst[2] = get_b(color);
	dst[3] = get_a(color);
}

void	ft_override_images(t_texture *dst, t_texture *src, t_vec v, int f)
{
	int		i;
	int		j;
	int		jf;
	char	*src_ptr;
	char	*dst_ptr;

	src_ptr = get_img_data(src->src).data;
	dst_ptr = get_img_data(dst->src).data;
	i = 0;
	while (i < src->h)
	{
		j = 0;
		while (j < src->w)
		{
			jf = j * (1 - f) + (src->w - j - 1) * f;
			if (v.x + jf >= 0 && v.x + jf < dst->w
				&& v.y + i >= 0 && v.y + i < dst->h)
			{
				ft_copy_pixel(&dst_ptr[(v.y + i) * dst->w * 4 + (v.x + j) * 4],
					&src_ptr[i * src->w * 4 + jf * 4]);
			}
			j++;
		}
		i++;
	}
}

void	ft_cover_pixel(char *dst, char *src)
{
	if (src[0] != 0)
	{
		dst[0] = src[0];
		dst[1] = src[1];
		dst[2] = src[2];
		dst[3] = src[3];
	}
}

void	ft_cover_images(t_texture *dst, t_texture *src, t_vec v, int f)
{
	int		i;
	int		j;
	int		jf;
	char	*src_ptr;
	char	*dst_ptr;

	src_ptr = get_img_data(src->src).data;
	dst_ptr = get_img_data(dst->src).data;
	i = 0;
	while (i < src->h)
	{
		j = 0;
		while (j < src->w)
		{
			jf = j * (1 - f) + (src->w - j - 1) * f;
			if (v.x + jf >= 0 && v.x + jf < dst->w
				&& v.y + i >= 0 && v.y + i < dst->h)
			{
				ft_cover_pixel(&dst_ptr[(v.y + i) * dst->w * 4 + (v.x + j) * 4],
					&src_ptr[i * src->w * 4 + jf * 4]);
			}
			j++;
		}
		i++;
	}
}

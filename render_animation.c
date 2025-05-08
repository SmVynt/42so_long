/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/08 20:25:50 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_next_frame_to_img(t_texture *target, t_animation *anim, int x, int y)
{
	anim->frame_time--;
	if (anim->frame_time <= 0)
	{
		anim->frame_time = anim->delta;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
			anim->frame = 0;
	}
	ft_override_images(target, &anim->src[anim->frame], x, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/30 03:16:08 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_next_frame_to_img(void *target, t_animation *anim)
{
	anim->frame_time--;
	if (anim->frame_time <= 0)
	{
		anim->frame_time = anim->delta;
		anim->cur_frame++;
		if (anim->cur_frame >= anim->frame_count)
			anim->cur_frame = 0;
	}
	target = anim->textures[anim->cur_frame].src;
}

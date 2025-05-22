/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/20 23:27:29 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_next_frame_to_img(t_texture *target,
			t_anim_list *anim_list, t_vec v, int f)
{
	t_animation	*anim;

	anim = anim_list->current;
	anim->frame_time--;
	if (anim->frame_time <= 0)
	{
		anim->frame_time = anim->delta;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			if (anim->next)
			{
				anim_list->current = anim->next;
				anim_list->current->frame = 0;
			}
			else
				anim->frame = 0;
		}
	}
	ft_override_images(target, &anim->src[anim->frame], v, f);
}

void	ft_next_frame_to_img_cover(t_texture *target,
			t_anim_list *anim_list, t_vec v, int f)
{
	t_animation	*anim;

	anim = anim_list->current;
	anim->frame_time--;
	if (anim->frame_time <= 0)
	{
		anim->frame_time = anim->delta;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			if (anim->next)
			{
				anim_list->current = anim->next;
				anim_list->current->frame = 0;
			}
			else
				anim->frame = 0;
		}
	}
	ft_cover_images(target, &anim->src[anim->frame], v, f);
}

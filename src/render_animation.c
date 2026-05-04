/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:56:00 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 03:56:10 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_anim_advance(t_anim_list *anim_list, double dt)
{
	t_animation	*anim;

	anim = anim_list->current;
	anim->acc += dt;
	while (anim->secs > 0.0 && anim->acc >= anim->secs)
	{
		anim->acc -= anim->secs;
		anim->frame++;
		if (anim->frame >= anim->frame_count)
		{
			if (anim->next)
			{
				anim_list->current = anim->next;
				anim_list->current->frame = 0;
				anim_list->current->acc = 0.0;
				anim = anim_list->current;
			}
			else
				anim->frame = 0;
		}
	}
}

void	ft_next_frame_to_img(t_texture *target,
			t_anim_list *anim_list, t_vec v, int f, double dt)
{
	t_animation	*anim;

	ft_anim_advance(anim_list, dt);
	anim = anim_list->current;
	ft_override_images(target, &anim->src[anim->frame], v, f);
}

void	ft_next_frame_to_img_cover(t_texture *target,
			t_anim_list *anim_list, t_vec v, int f, double dt)
{
	t_animation	*anim;

	ft_anim_advance(anim_list, dt);
	anim = anim_list->current;
	ft_cover_images(target, &anim->src[anim->frame], v, f);
}

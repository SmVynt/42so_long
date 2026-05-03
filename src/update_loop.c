/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 04:00:49 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void	ft_update_state(t_gs *game)
{
	if (game->state == STATE_HERO || game->state == STATE_ENEMIES)
	{
		game->turn = ft_lerp(game->turn, 1.0f, GAME_LERP);
		if (game->turn >= 0.99f)
		{
			game->turn = 1.0f;
			if (game->state == STATE_ENEMIES)
				game->state = STATE_CALC2;
			else if (game->state == STATE_HERO)
			{
				game->steps++;
				ft_update_count(game);
				game->state = STATE_CALC;
			}
		}
	}
	else if (game->state == STATE_CALC2)
		game->state = STATE_IDLE;
}

void	ft_update(void *param)
{
	t_gs	*game;
	size_t	n;

	game = (t_gs *)param;
	if (game->state == STATE_FINAL)
		return ;
	ft_update_state(game);
	ft_update_objs(game);
	ft_update_exit(game);
	ft_update_enemies(game);
	ft_update_hero(game);
	ft_update_end(game);
	ft_override_images(&game->img.render_sm, &game->img.bg, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.decor, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.en, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.fg, mk_vec(0, 0), 0);
	ft_scale_image_ca(&game->img.render_sm, &game->img.render);
	n = (size_t)game->img.render.w * (size_t)game->img.render.h * 4;
	memcpy(game->screen->pixels, game->img.render.src->pixels, n);
}

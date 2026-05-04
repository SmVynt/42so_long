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
#include <math.h>
#include <string.h>

static double	ft_clamp_dt(t_gs *game)
{
	double	dt;

	dt = game->mlx->delta_time;
	if (dt <= 0.0 || dt > 0.1)
		dt = 1.0 / ANIM_REF_FPS;
	return (dt);
}

static void	ft_update_state(t_gs *game, double dt)
{
	float	alpha;

	if (game->state == STATE_HERO || game->state == STATE_ENEMIES)
	{
		alpha = 1.0f - powf(1.0f - GAME_LERP, (float)(dt * ANIM_REF_FPS));
		game->turn = ft_lerp(game->turn, 1.0f, alpha);
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
	double	dt;

	game = (t_gs *)param;
	if (game->state == STATE_FINAL)
		return ;
	dt = ft_clamp_dt(game);
	ft_update_state(game, dt);
	ft_update_objs(game, dt);
	ft_update_exit(game, dt);
	ft_update_enemies(game, dt);
	ft_update_hero(game, dt);
	ft_update_end(game);
	ft_override_images(&game->img.render_sm, &game->img.bg, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.decor, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.en, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.fg, mk_vec(0, 0), 0);
	ft_scale_image_ca(&game->img.render_sm, &game->img.render);
	n = (size_t)game->img.render.w * (size_t)game->img.render.h * 4;
	memcpy(game->screen->pixels, game->img.render.src->pixels, n);
}

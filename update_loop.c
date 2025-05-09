/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/09 04:16:10 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int ft_tol(int a, int b)
{
	int tolerance = 1;

	if (a - b <= tolerance && a - b >= -tolerance)
		return (1);
	return (0);
}

static int ft_lerp(int a, int b, int t)
{
	float	d;

	d = (float)(b - a) / (float)t;
	if (d > -1.0f && d < 0.0f)
		d = -1.0f;
	if (d < 1.0f && d > 0.0f)
		d = 1.0f;
	return (a + (int)d);
}

static void	ft_update_hero(t_gamestate *game)
{
	t_hero	*hero;

	hero = &game->hero;
	if (hero->state == STATE_MOVE)
	{
		ft_override_images(&game->img.fg, &game->textures.erasor,
			mk_vec(hero->x,	hero->y - 12), 0);
		// hero->x = hero->x + hero->dir_x * MOVE_SPEED;
		// hero->y = hero->y + hero->dir_y * MOVE_SPEED;
		hero->x = ft_lerp(hero->x, hero->x_dest, MOVE_SPEED);
		hero->y = ft_lerp(hero->y, hero->y_dest, MOVE_SPEED);
		if (ft_tol(hero->x, hero->x_dest) && ft_tol(hero->y, hero->y_dest))
		{
			hero->x = hero->x_dest;
			hero->y = hero->y_dest;
			hero->state = STATE_IDLE;
			hero->anim.current = &hero->anim.idle;
		}
	}
	if (hero->state == STATE_IDLE)
	{
		if (hero->wish_x != 0 || hero->wish_y != 0)
		{
			hero->dir_x = hero->wish_x;
			hero->dir_y = hero->wish_y * (hero->dir_x == 0);
			hero->state = STATE_MOVE;
			hero->anim.current = &hero->anim.move;
			hero->x_dest = hero->x + hero->dir_x * TILE_S;
			hero->y_dest = hero->y + hero->dir_y * TILE_S;
		}
	}
	ft_next_frame_to_img(&game->img.fg, game->hero.anim.current,
		mk_vec(game->hero.x, game->hero.y - 12), game->hero.flipped);
}

int	ft_update(t_gamestate *game)
{
	ft_update_hero(game);
	ft_override_images(&game->img.render_sm, &game->img.bg, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.fg, mk_vec(0, 0), 0);
	ft_scale_image_ca(&game->img.render_sm, &game->img.render);
	mlx_put_image_to_window(game->mlx, game->window,
		game->img.render.src, 0, 0);
	return (0);
}

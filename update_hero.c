/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/13 02:51:38 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static float	ft_turn_progress(int x1, int x2, int y1, int y2)
{
	int		dx;
	int		dy;
	int		d;

	dx = x1 - x2;
	dy = y1 - y2;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	d = dy;
	if (dx > dy)
		d = dx;
	if (d > TILE_S)
		d = TILE_S;
	return (1.0f - ((float)d / (float)TILE_S));
}

static void	ft_update_hero_move(t_gamestate *game, t_hero *hero)
{
	ft_override_images(&game->img.fg, &game->textures.erasor,
		mk_vec(hero->x, hero->y - 12), 0);
	hero->x = ft_lerp(hero->x, hero->x_dest, MOVE_SPEED);
	hero->y = ft_lerp(hero->y, hero->y_dest, MOVE_SPEED);
	if (ft_tol(hero->x, hero->x_dest) && ft_tol(hero->y, hero->y_dest))
	{
		hero->x = hero->x_dest;
		hero->y = hero->y_dest;
		hero->state = STATE_IDLE;
		hero->anim.current = &hero->anim.idle;
		game->state = STATE_CALC;
	}
	game->turn = ft_turn_progress(hero->x, hero->x_dest, hero->y, hero->y_dest);
}

static void	ft_start_hero_move(t_gamestate *game, t_hero *hero)
{
	char	tile;

	tile = game->map.tile[(hero->x + hero->wish_x * TILE_S) / TILE_S]
	[(hero->y + hero->wish_y * TILE_S) / TILE_S];
	if (tile != '1')
	{
		hero->dir_x = hero->wish_x;
		hero->dir_y = hero->wish_y * (hero->dir_x == 0);
		hero->state = STATE_MOVE;
		hero->anim.current = &hero->anim.move;
		hero->x_dest = hero->x + hero->dir_x * TILE_S;
		hero->y_dest = hero->y + hero->dir_y * TILE_S;
	}
}

void	ft_update_hero(t_gamestate *game)
{
	t_hero	*hero;

	hero = &game->hero;
	if (hero->state == STATE_MOVE)
		ft_update_hero_move(game, hero);
	if (hero->state == STATE_IDLE)
	{
		game->turn = 0.0f;
		if (hero->wish_x != 0 || hero->wish_y != 0)
			ft_start_hero_move(game, hero);
	}
	ft_next_frame_to_img(&game->img.fg, game->hero.anim.current,
		mk_vec(game->hero.x, game->hero.y - 12), game->hero.flipped);
}

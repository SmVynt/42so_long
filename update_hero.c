/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/13 04:18:37 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static float	ft_turn_progress(int x1, int x2, int y1, int y2)
// {
// 	int		dx;
// 	int		dy;
// 	int		d;

// 	dx = x1 - x2;
// 	dy = y1 - y2;
// 	if (dx < 0)
// 		dx = -dx;
// 	if (dy < 0)
// 		dy = -dy;
// 	d = dy;
// 	if (dx > dy)
// 		d = dx;
// 	if (d > TILE_S)
// 		d = TILE_S;
// 	return (1.0f - ((float)d / (float)TILE_S));
// }

static void	ft_update_hero_move(t_gamestate *game, t_hero *hero)
{
	ft_override_images(&game->img.fg, &game->textures.erasor,
		mk_vec(hero->x, hero->y - 12), 0);
	hero->x = ft_lerp_int(hero->x_prev, hero->x_next, game->turn);
	hero->y = ft_lerp_int(hero->y_prev, hero->y_next, game->turn);
	// if ()
	// {
	// 	hero->x = hero->x_next;
	// 	hero->y = hero->y_next;
	// 	hero->state = STATE_IDLE;
	// 	hero->anim.current = &hero->anim.idle;
	// 	//game->state = STATE_CALC;
	// }
	//game->turn = ft_turn_progress(hero->x, hero->x_next, hero->y, hero->y_next);
}

static void	ft_start_hero_move(t_gamestate *game, t_hero *hero)
{
	char	tile;
	int		wish_y;

	if (hero->state != STATE_IDLE)
		return ;
	wish_y = hero->wish_y * (hero->wish_x == 0);
	tile = game->map.tile[(hero->x + hero->wish_x * TILE_S) / TILE_S]
	[(hero->y + wish_y * TILE_S) / TILE_S];
	if (tile != '1')
	{
		hero->x_prev = hero->x;
		hero->y_prev = hero->y;
		hero->state = STATE_MOVE;
		hero->anim.current = &hero->anim.move;
		hero->x_next = hero->x + hero->wish_x * TILE_S;
		hero->y_next = hero->y + wish_y * TILE_S;
		// printf("%d %d => %d %d", hero->x_prev, hero->y_prev, hero->x_next, hero->y_next);
		game->state = STATE_MOVE;
	}
	printf("dt %d\n", hero->x_next - hero->x_prev);
}

void	ft_update_hero(t_gamestate *game)
{
	t_hero	*hero;

	hero = &game->hero;
	if (game->state == STATE_CALC)
	{
		hero->x = hero->x_next;
		hero->y = hero->y_next;
		hero->state = STATE_IDLE;
		hero->anim.current = &hero->anim.idle;
	}
	if (hero->state == STATE_MOVE)
		ft_update_hero_move(game, hero);
	if (hero->state == STATE_IDLE)
	{
		if (hero->wish_x != 0 || hero->wish_y != 0)
			ft_start_hero_move(game, hero);
	}
	ft_next_frame_to_img(&game->img.fg, game->hero.anim.current,
		mk_vec(game->hero.x, game->hero.y - 12), game->hero.flipped);
}

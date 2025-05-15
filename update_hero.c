/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_hero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/16 00:30:30 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_hero_move(t_gamestate *game, t_hero *hero)
{
	ft_override_images(&game->img.fg, &game->textures.erasor,
		mk_vec(hero->x, hero->y - 12), 0);
	hero->x = ft_lerp_int(hero->x_prev * TS, hero->x_next * TS, game->turn);
	hero->y = ft_lerp_int(hero->y_prev * TS, hero->y_next * TS, game->turn);
}

static void	ft_start_hero_move(t_gamestate *game, t_hero *hero)
{
	char	tile;
	int		wish_y;

	wish_y = hero->wish_y * (hero->wish_x == 0);
	tile = game->map.tile[(hero->x + hero->wish_x * TS) / TS]
	[(hero->y + wish_y * TS) / TS];
	if (tile != '1')
	{
		hero->x_prev = hero->x / TS;
		hero->y_prev = hero->y / TS;
		hero->state = STATE_MOVE;
		hero->anim.current = &hero->anim.move;
		hero->x_next = hero->x_prev + hero->wish_x;
		hero->y_next = hero->y_prev + wish_y;
		game->state = STATE_HERO;
		game->turn = 0.0f;
	}
}

void	ft_update_hero(t_gamestate *game)
{
	t_hero	*hero;

	hero = &game->hero;
	if (game->state == STATE_IDLE || game->state == STATE_CALC2)
	{
		hero->x = hero->x_next * TS;
		hero->y = hero->y_next * TS;
		hero->state = STATE_IDLE;
		hero->anim.current = &hero->anim.idle;
		if (hero->wish_x != 0 || hero->wish_y != 0)
			ft_start_hero_move(game, hero);
	}
	else if (game->state == STATE_HERO)
		ft_update_hero_move(game, hero);
	ft_next_frame_to_img(&game->img.fg, game->hero.anim.current,
		mk_vec(game->hero.x, game->hero.y - 12), game->hero.flipped);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/16 01:04:11 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_find_next_spot(t_gamestate *game, t_enemy *enemy)
{
	int	i;

	enemy->x_prev = enemy->x_next;
	enemy->y_prev = enemy->y_next;
	enemy->x_next = enemy->x_dest;
	enemy->y_next = enemy->y_dest;
	if (enemy->x_dest > enemy->x / TS)
		enemy->x_next = enemy->x / TS + 1;
	if (enemy->x_dest < enemy->x / TS)
		enemy->x_next = enemy->x / TS - 1;
	if (enemy->y_dest > enemy->y / TS)
		enemy->y_next = enemy->y / TS + 1;
	if (enemy->y_dest < enemy->y / TS)
		enemy->y_next = enemy->y / TS - 1;
	i = -1;
	while (++i < game->c.enemies)
	{
		if (game->enemies[i].x_next == enemy->x_next &&
			game->enemies[i].y_next == enemy->y_next &&
			&game->enemies[i] != enemy)
		{
			enemy->x_next = enemy->x_prev;
			enemy->y_next = enemy->y_prev;
		}
	}
}

static void ft_update_enemy_move(t_gamestate *game, t_enemy *enemy)
{
	// ft_override_images(&game->img.en, &game->textures.erasor_sm,
	// 	mk_vec(enemy->x + TS / 6, enemy->y - 6 + TS / 6), 0);
	enemy->x = ft_lerp_int(enemy->x_prev * TS, enemy->x_next * TS, game->turn);
	enemy->y = ft_lerp_int(enemy->y_prev * TS, enemy->y_next * TS, game->turn);
}

static int	ft_check_reach(t_gamestate *game, t_vec a, t_vec b)
{
	int x_min;
	int	x_max;
	int	y_min;
	int y_max;
	int	i;
	int	j;

	x_min = ft_min(a.x, b.x);
	x_max = ft_max(a.x, b.x);
	y_min = ft_min(a.y, b.y);
	y_max = ft_max(a.y, b.y);
	i = x_min - 1;
	while (++i <= x_max)
	{
		j = y_min - 1;
		while (++j <= y_max)
		{
			if (game->map.tile[i][j] == '1')
				return (0);
		}
	}
	return (1);
}

static int	ft_enemy_search(t_gamestate *game, t_enemy *enemy)
{
	t_vec	e;
	t_vec	h;

	e.x = enemy->x_next;
	e.y = enemy->y_next;
	h.x = game->hero.x_next;
	h.y = game->hero.y_next;
	if (e.x == h.x || e.y == h.y)
	{
		if (ft_check_reach(game, mk_vec(e.x, e.y), mk_vec(h.x, h.y)) == 0)
			return (0);
		enemy->flipped = 0;
		enemy->x_dest = game->hero.x_next;
		enemy->y_dest = game->hero.y_next;
		if (enemy->x_dest < enemy->x / TS)
			enemy->flipped = 1;
		enemy->state = STATE_MOVE;
		enemy->anim.current = &enemy->anim.move;
		return (1);
	}
	return (0);
}

void	ft_update_enemies(t_gamestate *game)
{
	int		i;
	t_enemy	*enemy;

	ft_clean_texture(&game->img.en);
	i = 0;
	while (i < game->c.enemies)
	{
		enemy = &game->enemies[i];
		if (game->state == STATE_CALC)
		{
			game->turn = 0.0f;
			enemy->x = enemy->x_next * TS;
			enemy->y = enemy->y_next * TS;
			if (enemy->x_dest == enemy->x / TS && enemy->y_dest == enemy->y / TS)
				enemy->anim.current = &enemy->anim.idle;
			ft_enemy_search(game, enemy);
			ft_find_next_spot(game, enemy);
		}
		else if (game->state == STATE_CALC2)
			ft_enemy_search(game, enemy);
		if (game->state == STATE_ENEMIES && enemy->state == STATE_MOVE)
			ft_update_enemy_move(game, enemy);
		ft_next_frame_to_img_cover(&game->img.en, enemy->anim.current,
			mk_vec(enemy->x, enemy->y - 6), enemy->flipped);
		i++;
	}
	if (game->state == STATE_CALC)
		game->state = STATE_ENEMIES;
}

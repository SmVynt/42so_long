/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/13 02:52:03 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	ft_update_enemy_move(t_gamestate *game, t_enemy *enemy)
// {
// 	ft_override_images(&game->img.fg, &game->textures.erasor,
// 		mk_vec(enemy->x, enemy->y - 6), 0);
// 	hero->x = ft_lerp(hero->x, hero->x_dest, MOVE_SPEED);
// 	hero->y = ft_lerp(hero->y, hero->y_dest, MOVE_SPEED);
// 	if (ft_tol(hero->x, hero->x_dest) && ft_tol(hero->y, hero->y_dest))
// 	{
// 		hero->x = hero->x_dest;
// 		hero->y = hero->y_dest;
// 		hero->state = STATE_IDLE;
// 		hero->anim.current = &hero->anim.idle;
// 	}
// }

static int	ft_check_reach(t_gamestate *game, t_vec a, t_vec b)
{
	int x_min;
	int	x_max;
	int	y_min;
	int y_max;
	int	i;

	x_min = ft_min(a.x, b.x);
	x_max = ft_max(a.x, b.x);
	y_min = ft_min(a.y, b.y);
	y_max = ft_max(a.y, b.y);
	printf("%d:%d || %d:%d\n",x_min, y_min, x_max, y_max);
	i = x_min - 1;
	while (++i <= x_max)
	{
		if (game->map.tile[i][y_max] == '1')
			return (0);
	}
	i = y_min - 1;
	while (++i <= y_max)
	{
		if (game->map.tile[x_max][i] == '1')
			return (0);
	}
	return (1);
}

static int	ft_enemy_search(t_gamestate *game, t_enemy *enemy)
{
	t_vec	e;
	t_vec	h;

	e.x = enemy->x / TILE_S;
	e.y = enemy->y / TILE_S;
	h.x = game->hero.x / TILE_S;
	h.y = game->hero.y / TILE_S;
	if (e.x == h.x || e.y == h.y)
	{
		if (ft_check_reach(game, mk_vec(e.x, e.y), mk_vec(h.x, h.y)) == 0)
			return (0);
		enemy->flipped = 0;
		enemy->x_dest = h.x;
		if (enemy->x_dest < enemy->x)
			enemy->flipped = 1;
		enemy->y_dest = h.y;
		return (1);
	}
	return (0);
}

// static void	ft_start_hero_move(t_gamestate *game, t_hero *hero)
// {
// 	char	tile;

// 	tile = game->map.tile[(hero->x + hero->wish_x * TILE_S) / TILE_S]
// 	[(hero->y + hero->wish_y * TILE_S) / TILE_S];
// 	if (tile != '1')
// 	{
// 		hero->dir_x = hero->wish_x;
// 		hero->dir_y = hero->wish_y * (hero->dir_x == 0);
// 		hero->state = STATE_MOVE;
// 		hero->anim.current = &hero->anim.move;
// 		hero->x_dest = hero->x + hero->dir_x * TILE_S;
// 		hero->y_dest = hero->y + hero->dir_y * TILE_S;
// 	}
// }

void	ft_update_enemies(t_gamestate *game)
{
	int		i;
	t_enemy	*enemy;

	i = 0;
	while (i < game->c.enemies)
	{
		enemy = &game->enemies[i];
		if (enemy->state == STATE_IDLE)
		{
			if (game->state == STATE_CALC)
			{
				if (ft_enemy_search(game, enemy) == 1)
				{
					enemy->state = STATE_MOVE;
					enemy->anim.current = &enemy->anim.move;
					printf("found!\n");
				}
			}
		}
		if (enemy->state == STATE_MOVE)
		{
		}
		ft_next_frame_to_img(&game->img.fg, enemy->anim.current,
			mk_vec(enemy->x, enemy->y - 6), enemy->flipped);
		i++;
	}
}

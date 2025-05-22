/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 00:56:32 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_enemy(t_enemy *enemy, int x, int y)
{
	enemy->x = x * TS;
	enemy->y = y * TS;
	enemy->x_next = x;
	enemy->y_next = y;
	enemy->x_dest = x;
	enemy->y_dest = y;
	enemy->state = STATE_IDLE;
	enemy->flipped = 0;
}

static void	ft_init_collect(t_collect *collect, int x, int y)
{
	collect->x = x * TS;
	collect->y = y * TS;
	collect->active = 1;
	collect->state = STATE_IDLE;
}

static void	ft_init_exit(t_gamestate *game, int x, int y)
{
	game->exit.x = x * TS;
	game->exit.y = y * TS;
	game->exit.state = STATE_IDLE;
	game->exit.active = 0;
	game->map.tile[x][y] = C_E;
}

void	ft_init_enemies(t_gamestate *game)
{
	int	x;
	int	y;
	int	i;

	if (game->c.enemies <= 0)
		return ;
	if (game->alloc.enemies == 0)
		game->enemies = malloc(sizeof(t_enemy) * game->c.enemies);
	if (!game->enemies)
		ft_exit_error("Could not allocate memory for enemies\n");
	game->alloc.enemies = 1;
	x = -1;
	i = 0;
	while (++x < game->map.w)
	{
		y = -1;
		while (++y < game->map.h)
		{
			if (game->map.tile[x][y] == C_EN)
			{
				ft_init_enemy(&game->enemies[i], x, y);
				i++;
			}
		}
	}
}

void	ft_init_objs(t_gamestate *game)
{
	int	x;
	int	y;
	int	i;

	if (game->alloc.collects == 0)
		game->collects = malloc(sizeof(t_collect) * game->c.collectibles);
	if (!game->collects)
		ft_exit_error("Could not allocate memory for collectibles\n");
	game->alloc.collects = 1;
	x = -1;
	i = 0;
	while (++x < game->map.w)
	{
		y = -1;
		while (++y < game->map.h)
		{
			if (game->map.tile[x][y] == C_C)
			{
				if (i < game->c.collectibles)
					ft_init_collect(&game->collects[i++], x, y);
			}
			if (game->map.tile[x][y] == C_EX)
				ft_init_exit(game, x, y);
		}
	}
}

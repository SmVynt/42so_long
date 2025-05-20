/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_objs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/21 01:12:35 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_enemy(t_gamestate *game, int *i, int x, int y)
{
	printf("Enemy %d initialized at (%d, %d)\n", *i, x, y);
	game->enemies[*i].x = x * TS;
	game->enemies[*i].y = y * TS;
	game->enemies[*i].x_next = x;
	game->enemies[*i].y_next = y;
	game->enemies[*i].x_dest = x;
	game->enemies[*i].y_dest = y;
	game->enemies[*i].state = STATE_IDLE;
	game->enemies[*i].flipped = 0;
	(*i) += 1;
}

static void	ft_init_collect(t_gamestate *game, int *i, int x, int y)
{
	game->collects[*i].x = x * TS;
	game->collects[*i].y = y * TS;
	game->collects[*i].active = 1;
	game->collects[*i].state = STATE_IDLE;
	(*i) += 1;
}

static void	ft_init_exit(t_gamestate *game, int x, int y)
{
	game->exit.x = x * TS;
	game->exit.y = y * TS;
	game->exit.state = STATE_IDLE;
	game->exit.active = 0;
	game->map.tile[x][y] = C_EM;
}

void	ft_init_enemies(t_gamestate *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	if (!game->enemies)
		game->enemies = malloc(sizeof(t_enemy) * game->c.enemies);
	if (!game->enemies)
		ft_exit_error("Could not allocate memory for enemies\n");
	x = -1;
	while (++x < game->map.w)
	{
		y = -1;
		while (++y < game->map.h)
		{
			if (game->map.tile[x][y] == C_EN)
				ft_init_enemy(game, &i, x, y);
		}
	}
}

void	ft_init_objs(t_gamestate *game)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	if (!game->collects)
		game->collects = malloc(sizeof(t_collect) * game->c.collectibles);
	if (!game->collects)
		ft_exit_error("Could not allocate memory for collectibles\n");
	x = -1;
	while (++x < game->map.w)
	{
		y = -1;
		while (++y < game->map.h)
		{
			if (game->map.tile[x][y] == C_CL)
				ft_init_collect(game, &i, x, y);
			if (game->map.tile[x][y] == C_EX)
				ft_init_exit(game, x, y);
		}
	}
}

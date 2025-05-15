/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/15 22:46:06 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_hero(t_gamestate *game)
{
	int	i;
	int	j;

	game->hero.wish_x = 0;
	game->hero.wish_y = 0;
	game->hero.state = STATE_IDLE;
	game->hero.flipped = 0;
	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == 'P')
			{
				game->hero.x = i * TILE_S;
				game->hero.y = j * TILE_S;
				game->map.tile[i][j] = '0';
			}
		}
	}
	game->hero.x_prev = game->hero.x;
	game->hero.y_prev = game->hero.y;
	game->hero.x_next = game->hero.x;
	game->hero.y_next = game->hero.y;
}

void	ft_init_enemies(t_gamestate *game)
{
	int	x;
	int	y;
	int i;

	i = 0;
	x = -1;
	printf("Initializing enemies\n");
	while (++x < game->map.w)
	{
		y = -1;
		while (++y < game->map.h)
		{
			if (game->map.tile[x][y] == 'X')
			{
				game->enemies[i].x = x * TILE_S;
				game->enemies[i].y = y * TILE_S;
				game->enemies[i].x_next = x * TILE_S;
				game->enemies[i].y_next = y * TILE_S;
				game->enemies[i].x_dest = x * TILE_S;
				game->enemies[i].y_dest = y * TILE_S;
				game->enemies[i].state = STATE_IDLE;
				game->enemies[i++].flipped = 0;
			}
		}
	}
}

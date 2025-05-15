/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/13 04:04:59 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_bounds(t_gamestate *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.w)
	{
		if (game->map.tile[x][0] != '1'
			|| game->map.tile[x][game->map.h - 1] != '1')
			ft_exit("Error\nMap is not surrounded by walls\n");
		x++;
	}
	y = 0;
	while (y < game->map.h)
	{
		if (game->map.tile[0][y] != '1'
			|| game->map.tile[game->map.w - 1][y] != '1')
			ft_exit("Error\nMap is not surrounded by walls\n");
		y++;
	}
}

static void	ft_check_characters(t_gamestate *game)
{
	int	i;
	int	j;

	game->c.collectibles = 0;
	game->c.exit = 0;
	game->c.start = 0;
	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == 'C')
				game->c.collectibles++;
			else if (game->map.tile[i][j] == 'E')
				game->c.exit++;
			else if (game->map.tile[i][j] == 'P')
				game->c.start++;
			else if (game->map.tile[i][j] == 'X')
				game->c.enemies++;
			else if (game->map.tile[i][j] != '1' && game->map.tile[i][j] != '0')
				ft_exit("Error\nInvalid character in map\n");
		}
	}
}

static void	ft_check_count(t_gamestate *game)
{
	if (game->c.collectibles < 1)
		ft_exit("Error\nNo collectibles in map\n");
	if (game->c.exit != 1)
		ft_exit("Error\nThere must be exactly one exit\n");
	if (game->c.start != 1)
		ft_exit("Error\nThere must be exactly one start position\n");
}

static void	ft_check_reach(t_gamestate *game)
{
	t_map	map_reach;
	int		i;
	int		j;

	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
			map_reach.tile[i][j] = game->map.tile[i][j];
	}
	map_reach.w = game->map.w;
	map_reach.h = game->map.h;
	ft_flood_fill(&map_reach, 'P');
	printf("Map reachability filled\n");
	j = -1;
	while (++j < game->map.h)
	{
		i = -1;
		while (++i < game->map.w)
		{
			if (map_reach.tile[i][j] == 'C' || map_reach.tile[i][j] == 'E')
				ft_exit("Error\nMap is not reachable\n");
		}
	}
}

void	ft_init_hero(t_gamestate *game)
{
	int	i;
	int	j;

	game->turn = 0.0f;
	game->hero.wish_x = 0;
	game->hero.wish_y = 0;
	game->hero.alive = 1;
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
				game->enemies[i].x_dest = x * TILE_S;
				game->enemies[i].y_dest = y * TILE_S;
				game->enemies[i].state = STATE_IDLE;
				game->enemies[i].flipped = 0;
				i++;
			}
		}
	}
}

void	ft_check_map(t_gamestate *game)
{
	if (game->map.w < 3 || game->map.h < 3)
		ft_exit("Error\nMap is too small\n");
	ft_check_bounds(game);
	printf("Map bounds checked\n");
	ft_check_characters(game);
	printf("Map characters checked\n");
	ft_check_count(game);
	printf("Map counts checked\n");
	ft_check_reach(game);
	printf("Map reachability checked\n");
	// ft_init_collectibles(game);
}

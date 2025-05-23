/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 01:44:39 by psmolin          ###   ########.fr       */
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
		if (game->map.tile[x][0] != C_W
			|| game->map.tile[x][game->map.h - 1] != C_W)
			ft_exit("Map is not surrounded by walls\n", game);
		x++;
	}
	y = 0;
	while (y < game->map.h)
	{
		if (game->map.tile[0][y] != C_W
			|| game->map.tile[game->map.w - 1][y] != C_W)
			ft_exit("Map is not surrounded by walls\n", game);
		y++;
	}
}

static void	ft_check_characters(t_gamestate *game)
{
	int	i;
	int	j;

	game->c.enemies = 0;
	game->c.collectibles = 0;
	game->c.exit = 0;
	game->c.start = 0;
	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == C_C)
				game->c.collectibles++;
			else if (game->map.tile[i][j] == C_EX)
				game->c.exit++;
			else if (game->map.tile[i][j] == C_P)
				game->c.start++;
			else if (game->map.tile[i][j] == C_EN)
				game->c.enemies++;
			else if (game->map.tile[i][j] != C_W && game->map.tile[i][j] != C_E)
				ft_exit("Invalid character in map\n", game);
		}
	}
}

static void	ft_check_count(t_gamestate *game)
{
	if (game->c.collectibles < 1)
		ft_exit("No collectibles in map\n", game);
	if (game->c.exit != 1)
		ft_exit("There must be exactly one exit\n", game);
	if (game->c.start != 1)
		ft_exit("There must be exactly one start position\n", game);
}

static void	ft_check_reach(t_gamestate *game)
{
	t_map	*map_reach;
	int		i;
	int		j;

	map_reach = ft_copy_map(&game->map);
	map_reach->w = game->map.w;
	map_reach->h = game->map.h;
	ft_flood_fill(map_reach, C_P);
	j = -1;
	while (++j < game->map.h)
	{
		i = -1;
		while (++i < game->map.w)
		{
			if (map_reach->tile[i][j] == C_C || map_reach->tile[i][j] == C_EX)
				ft_exit("Map is not reachable\n", game);
		}
	}
	ft_free_map(map_reach);
}

void	ft_check_map(t_gamestate *game)
{
	ft_printf(COLOR_Y "Checking map.\n" COLOR_X);
	ft_printf(COLOR_W "Checking bounds. " COLOR_X);
	ft_check_bounds(game);
	ft_printf(COLOR_G "Checked\n" COLOR_X);
	ft_printf(COLOR_W "Checking map characters. " COLOR_X);
	ft_check_characters(game);
	ft_printf(COLOR_G "Checked\n" COLOR_X);
	ft_printf(COLOR_W "Checking objects count. " COLOR_X);
	ft_check_count(game);
	ft_printf(COLOR_G "Checked\n" COLOR_X);
	ft_printf(COLOR_W "Checking map reachibilty. " COLOR_X);
	ft_check_reach(game);
	ft_printf(COLOR_G "Checked\n" COLOR_X);
}

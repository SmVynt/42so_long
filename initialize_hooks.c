/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/12 17:01:55 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_key_press_hook(int keycode, t_gamestate *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	else if (keycode == 0 || keycode == 123)
	{
		game->hero.wish_x = -1;
		game->hero.flipped = 1;
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->hero.wish_x = 1;
		game->hero.flipped = 0;
	}
	else if (keycode == 13 || keycode == 126)
	{
		game->hero.wish_y = -1;
	}
	else if (keycode == 1 || keycode == 125)
	{
		game->hero.wish_y = 1;
	}
	return (game->steps);
}

static int	ft_key_release_hook(int keycode, t_gamestate *game)
{
	if (keycode == 0 || keycode == 123)
	{
		game->hero.wish_x = 0;
		game->hero.wish_y = 0;
	}
	else if (keycode == 2 || keycode == 124)
	{
		game->hero.wish_x = 0;
		game->hero.wish_y = 0;
	}
	else if (keycode == 13 || keycode == 126)
	{
		game->hero.wish_x = 0;
		game->hero.wish_y = 0;
	}
	else if (keycode == 1 || keycode == 125)
	{
		game->hero.wish_x = 0;
		game->hero.wish_y = 0;
	}
	return (game->steps);
}

void	ft_createhooks(t_gamestate *game)
{
	mlx_hook(game->window, 2, 1L << 0, ft_key_press_hook, game);
	mlx_hook(game->window, 3, 1L << 1, ft_key_release_hook, game);
	mlx_hook(game->window, 17, 1L << 2, ft_exit_game, game);
	mlx_loop_hook(game->mlx, ft_update, game);
}

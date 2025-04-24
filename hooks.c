/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/24 13:45:15 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_key_press_hook(int keycode, t_gamestate *game)
{
	if (keycode == 53)
		ft_exit_game(game);
	else if (keycode == 0 || keycode == 123)
		printf("LEFT\n");
	else if (keycode == 2 || keycode == 124)
		printf("RIGHT\n");
	else if (keycode == 13 || keycode == 126)
		printf("UP\n");
	else if (keycode == 1 || keycode == 125)
		printf("DOWN\n");
	return (game->steps);
}

static int	ft_key_release_hook(int keycode, t_gamestate *game)
{
	if (keycode == 53)
		printf("exit\n");
	else if (keycode == 0 || keycode == 123)
		printf("left\n");
	else if (keycode == 2 || keycode == 124)
		printf("right\n");
	else if (keycode == 13 || keycode == 126)
		printf("up\n");
	else if (keycode == 1 || keycode == 125)
		printf("down\n");
	return (game->steps);
}

void	ft_createhooks(t_gamestate *game)
{
	mlx_hook(game->img.window, 2, 1L << 0, ft_key_press_hook, game);
	mlx_hook(game->img.window, 3, 1L << 1, ft_key_release_hook, game);
	mlx_hook(game->img.window, 17, 1L << 2, ft_exit_game, game);
	// mlx_loop_hook(img->mlx, ft_render, game);
}
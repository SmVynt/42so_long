/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hooks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 22:16:51 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 02:27:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_gs	*game;

	game = (t_gs *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit_game(game);
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ft_restart(game);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		{
			game->hero.wish_x = -1;
			game->hero.flipped = 1;
		}
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		{
			game->hero.wish_x = 1;
			game->hero.flipped = 0;
		}
		else if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			game->hero.wish_y = -1;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			game->hero.wish_y = 1;
	}
	else if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT
			|| keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT
			|| keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP
			|| keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		{
			game->hero.wish_x = 0;
			game->hero.wish_y = 0;
		}
	}
}

static void	ft_close_hook(void *param)
{
	ft_exit_game((t_gs *)param);
}

void	ft_createhooks(t_gs *game)
{
	mlx_close_hook(game->mlx, ft_close_hook, game);
	mlx_key_hook(game->mlx, ft_key_hook, game);
	mlx_loop_hook(game->mlx, ft_update, game);
}

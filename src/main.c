/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 01:54:32 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_gamestate	game;

	ft_checkinput (argc, argv, &game);
	ft_initialize (&game, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_exit_error("Could not initialize MiniLibX\n", &game);
	game.window = mlx_new_window(game.mlx, game.map.w * SCALE * TS,
			game.map.h * SCALE * TS, "So Long...");
	ft_createhooks(&game);
	ft_init_images(&game);
	ft_fill_tilemap(&game);
	ft_update_count(&game);
	mlx_loop(game.mlx);
	ft_exit_error("MiniLibX looping error.\n", &game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/22 18:18:45 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_gamestate	game;

	ft_checkinput (argc, argv);
	ft_initialize (&game, argv);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_exit_error("Error\nCould not initialize MiniLibX\n");
	game.window = mlx_new_window(game.mlx, game.map.w * SCALE * TS,
			game.map.h * SCALE * TS, "So Long...");
	ft_createhooks(&game);
	ft_init_images(&game);
	ft_fill_tilemap(&game);
	ft_printf ("Map initialized\n");
	ft_update_count(&game);
	ft_printf ("Map filled\n");
	mlx_loop(game.mlx);
	ft_exit_error("Error\nMiniLibX looping error.\n");
	return (0);
}

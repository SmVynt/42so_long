/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/08 15:36:53 by psmolin          ###   ########.fr       */
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
	game.window = mlx_new_window(game.mlx, game.map.width * SCALE * TILE_SIZE,
		game.map.height * SCALE * TILE_SIZE, "So Long...");
	ft_createhooks(&game);
	ft_initialize_images(&game);
	ft_fill_tilemap(&game);
	ft_scale_image_ca(&game.img.bg, &game.img.render);
	mlx_put_image_to_window(game.mlx, game.window,
		game.img.render.src, 0, 0);
	mlx_loop(game.mlx);
	
	ft_exit_error("Error\nMiniLibX looping error.\n");
	return (0);
}

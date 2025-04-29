/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/29 18:56:47 by psmolin          ###   ########.fr       */
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
	game.window = mlx_new_window(game.mlx, SCRN_W, SCRN_H,
		"So Long...");
	//game.img.img = mlx_new_image(game.img.mlx, SCRN_W, SCRN_H);
	//game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bpp,
	//		&game.img.size_line, &game.img.endian);
	ft_createhooks(&game);
	ft_initialize_images(&game);
	mlx_put_image_to_window(game.mlx, game.window,
		game.textures.bg.srs, 0, 0);
	mlx_loop(game.mlx);
	ft_exit_error("Error\nMiniLibX looping error.\n");
	return (0);
}

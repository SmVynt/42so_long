/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:12 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/26 22:55:53 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

int	main(int argc, char **argv)
{
	t_gs	game;

	memset(&game, 0, sizeof(game));
	ft_checkinput(argc, argv, &game);
	ft_initialize(&game, argv);
	game.mlx = mlx_init(game.map.w * SCALE * TS, game.map.h * SCALE * TS,
			"So Long...", false);
	if (!game.mlx)
		ft_exit_error("Could not initialize MLX42\n", &game);
	ft_createhooks(&game);
	ft_init_images(&game);
	ft_fill_tilemap(&game);
	ft_update_count(&game);
	mlx_loop(game.mlx);
	ft_exit_error("MLX42 loop error.\n", &game);
	return (0);
}

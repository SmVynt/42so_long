/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/15 21:20:11 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkinput(int argc, char **argv)
{
	if (argc != 2 || ft_strlen(argv[1]) < 5
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_exit("Error\nPlease run the game with this command:\
			\n./so_long maps/<mapname.ber>\n");
	}
}

static void	ft_fill_map(t_gamestate *game, int fd)
{
	int		buffer_size;
	char	buffer;
	int		i;

	buffer_size = read(fd, &buffer, 1);
	game->map.w = 1;
	game->map.h = 1;
	i = 0;
	while (buffer_size > 0)
	{
		if (i > MAX_WIDTH || game->map.h > MAX_HEIGHT)
			ft_exit("Error\nMap is too large\n");
		game->map.tile[i][game->map.h - 1] = buffer;
		if (buffer == '\n')
		{
			game->map.h++;
			if (game->map.w == 1)
				game->map.w = i;
			else if (i != game->map.w)
				ft_exit("Error\nMap is not rectangular\n");
			i = -1;
		}
		i++;
		buffer_size = read(fd, &buffer, 1);
	}
}

void	ft_initialize(t_gamestate *game, char **argv)
{
	int	fd;

	fd = open (argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nCould not open the map file\n");
	ft_fill_map(game, fd);
	close(fd);
	ft_check_map(game);
	ft_init_hero(game);
	ft_init_enemies(game);
	game->state = STATE_CALC;
	game->turn = 0.0f;
}

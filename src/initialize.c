/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 01:55:26 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_checkinput(int argc, char **argv, t_gamestate *game)
{
	if (argc != 2 || ft_strlen(argv[1]) < 5
		|| ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_exit("Please run the game with this command:\
			\n./so_long maps/<mapname.ber>\n", game);
	}
}

static void	ft_calculate_map_size(t_gamestate *game, char *src)
{
	int		fd;
	char	*line;

	fd = open (src, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nCould not open the map file\n", game);
	line = ft_strip_from_n(get_next_line(fd));
	if (!line)
		ft_exit("Map is empty\n", game);
	game->map.w = (int)ft_strlen(line);
	game->map.h = 0;
	while (line)
	{
		if (ft_strlen(line) != (size_t)game->map.w)
			ft_exit("Map is not rectangular\n", game);
		free(line);
		line = ft_strip_from_n(get_next_line(fd));
		game->map.h++;
	}
	close(fd);
	if (game->map.w < 3 || game->map.h < 3)
		ft_exit("Map is too small\n", game);
}

static void	ft_fill_map(t_gamestate *game, char *src)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	ft_allocate_map(&game->map, game);
	fd = open (src, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Error\nCould not open the map file\n", game);
	line = ft_strip_from_n(get_next_line(fd));
	i = 0;
	while (line)
	{
		j = -1;
		while (++j < game->map.w)
			game->map.tile[j][i] = line[j];
		free(line);
		line = ft_strip_from_n(get_next_line(fd));
		i++;
	}
	game->alloc.map = 1;
}

void	ft_restart(t_gamestate *game)
{
	int	i;

	ft_init_hero(game);
	ft_init_enemies(game);
	ft_init_objs(game);
	game->state = STATE_IDLE;
	game->turn = 0.0f;
	game->steps = 0;
	game->collected = 0;
	game->exit.active = 0;
	ft_clean_texture(&game->img.fg);
	ft_update_count(game);
	i = -1;
	while (++i < game->c.collectibles)
	{
		game->collects[i].active = 1;
		game->collects[i].anim.current = &game->collects[i].anim.idle;
	}
	i = -1;
	while (++i < game->c.enemies)
		game->enemies[i].anim.current = &game->enemies[i].anim.idle;
	game->exit.anim.current = &game->exit.anim.idle;
	game->exit.active = 0;
}

void	ft_initialize(t_gamestate *game, char **argv)
{
	game->alloc.map = 0;
	game->alloc.enemies = 0;
	game->alloc.collects = 0;
	ft_calculate_map_size(game, argv[1]);
	ft_fill_map(game, argv[1]);
	ft_check_map(game);
	ft_init_hero(game);
	ft_init_enemies(game);
	ft_init_objs(game);
	game->state = STATE_CALC;
	game->turn = 0.0f;
	game->steps = 0;
	game->collected = 0;
	game->exit.active = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:05 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/24 13:40:25 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAX_ENEMIES 10
# define MAX_WIDTH 80
# define MAX_HEIGHT 45
# define SCRN_W 1280
# define SCRN_H 720

typedef struct s_map
{
	int		width;
	int		height;
	char	tile[MAX_WIDTH + 1][MAX_HEIGHT + 1];
	int		checked;
}	t_map;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
	int	speed;
	int	alive;
}	t_enemy;

typedef struct s_hero
{
	int	x;
	int	y;
	int	x_target;
	int	y_target;
	int	is_moving;
}	t_hero;

typedef struct s_imgdata
{
	void 	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_imgdata;

typedef struct s_gamestate
{
	t_map		map;
	t_imgdata	img;
	int			steps;
	t_enemy		enemies[MAX_ENEMIES];
	t_hero		hero;
	int			c_collectibles;
	int			c_exit;
	int			c_start;
	int			c_enemies;
}	t_gamestate;

void	ft_exit_error(char *str);
void	ft_exit(char *str);
int		ft_exit_game(t_gamestate *game);
void	ft_createhooks(t_gamestate *game);
void	ft_checkinput(int argc, char **argv);
void	ft_initialize(t_gamestate *game, char **argv);
void	ft_check_map(t_gamestate *game);
void	ft_flood_fill(t_map *map, char start);

#endif
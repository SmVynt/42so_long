/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:05 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/29 20:04:55 by psmolin          ###   ########.fr       */
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
# define TILE_SIZE 32

typedef struct s_map
{
	int		width;
	int		height;
	char	tile[MAX_WIDTH + 1][MAX_HEIGHT + 1];
	int		checked;
}	t_map;

typedef struct s_texture
{
	void	*srs;
	int		w;
	int		h;
}	t_texture;

typedef struct s_animation
{
	t_texture	*textures;
	int			frame_count;
	int			frame_time;
	int			cur_frame;
	int			delta;
}	t_animation;

typedef struct s_textures
{
	t_texture	bg;
	t_texture	hero;
	t_texture	enemy;
	t_texture	collectible;
	t_texture	exit;
}	t_textures;

typedef struct s_enemy
{
	int	x;
	int	y;
	int	direction;
	int	alive;
}	t_enemy;

typedef struct s_hero
{
	int	x;
	int	y;
}	t_hero;

typedef struct s_count
{
	int	collectibles;
	int	exit;
	int	start;
	int	enemies;
}	t_count;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;

	void	*bg;
	void	*characters;
}	t_imgdata;

typedef struct s_gamestate
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_imgdata	img;
	int			steps;
	t_enemy		enemies[MAX_ENEMIES];
	t_hero		hero;
	t_count		c;
	t_textures	textures;
}	t_gamestate;

void	ft_exit_error(char *str);
void	ft_exit(char *str);
int		ft_exit_game(t_gamestate *game);
void	ft_createhooks(t_gamestate *game);
void	ft_checkinput(int argc, char **argv);
void	ft_initialize_images(t_gamestate *game);
void	ft_initialize(t_gamestate *game, char **argv);
void	ft_check_map(t_gamestate *game);
void	ft_flood_fill(t_map *map, char start);

void	ft_next_frame_to_img(void *target, t_animation *anim);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:05:05 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/08 14:37:34 by psmolin          ###   ########.fr       */
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
# define TILE_SIZE 32
# define SCALE 3
# define FRAME_TIME 3

# define STATE_IDLE 0
# define STATE_MOVE 1
# define STATE_DEATH 2
# define STATE_DEAD 3

# define PATH_TILES "./textures/bg_tileset_02.xpm"
# define PATH_HERO_IDLE "./textures/hero_01.xpm"
# define PATH_HERO_MOVE "./textures/hero_run.xpm"

typedef struct s_map
{
	int		width;
	int		height;
	char	tile[MAX_WIDTH + 1][MAX_HEIGHT + 1];
	int		checked;
}	t_map;

typedef struct s_texture
{
	void	*src;
	int		w;
	int		h;
}	t_texture;

typedef struct s_animation
{
	t_texture	*src;
	int			frame;
	int			frame_count;
	int			frame_time;
	int			delta;
}	t_animation;

typedef struct s_anim_list
{
	t_animation *current;
	t_animation idle;
	t_animation move;
	t_animation death;
} t_anim_list;

typedef struct s_textures
{
	t_texture	bg;
	t_texture	tileset;
	t_texture	tiles[16];
	t_texture	hero_idle[4];
	t_texture	hero_move[4];
	t_texture	hero_death[4];
	t_texture	enemy_idle[4];
	t_texture	enemy_move[4];
	t_texture	enemy_death[4];
	t_texture	coll_idle[4];
	t_texture	coll_take[4];
	t_texture	exit_idle[4];
	t_texture	exit_open[4];
	t_texture	temp;
}	t_textures;

typedef struct s_hero
{
	int			x;
	int			y;
	int			direction;
	int			alive;
	int			state;
	t_anim_list anim;
}	t_hero;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			direction;
	int			alive;
	int			state;
	t_anim_list anim;
}	t_enemy;

typedef struct s_collectible
{
	int			x;
	int			y;
	int			active;
	int			state;
	t_anim_list anim;
}	t_collectible;

typedef struct s_exit
{
	int			x;
	int			y;
	int			active;
	int			state;
	t_anim_list anim;
}	t_exit;

typedef struct s_count
{
	int	collectibles;
	int	exit;
	int	start;
	int	enemies;
}	t_count;

typedef struct s_imgdt
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
}	t_imgdt;

typedef struct s_render
{
	t_texture	bg;
	t_texture	decor;
	t_texture	fg;
	t_texture	render_sm;
	t_texture	render;
}	t_render;

typedef struct s_gamestate
{
	void		*mlx;
	void		*window;
	t_render	img;
	t_map		map;
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
void	ft_initialize_texture(t_texture *texture,
			t_gamestate *game, int w, int h);
void	ft_initialize(t_gamestate *game, char **argv);

void	ft_check_map(t_gamestate *game);
void	ft_flood_fill(t_map *map, char start);
void	ft_fill_tilemap(t_gamestate *game);

void	ft_next_frame_to_img(t_texture *target, t_animation *anim, int x, int y);

void	ft_scale_image(t_texture *src, t_texture *dst);
void	ft_scale_image_ca(t_texture *src, t_texture *dst);
void	ft_override_images(t_texture *dst, t_texture *src, int x, int y);
void	ft_cover_images(t_texture *dst, t_texture *src, int x, int y);
void	ft_copy_pixel(char *dst, char *src);
void	ft_cover_pixel(char *dst, char *src);

int		get_rgba(int r, int g, int b, int a);
int		get_r(int rgba);
int		get_g(int rgba);
int		get_b(int rgba);
int		get_a(int rgba);

t_imgdt	get_img_data(void *img);

#endif
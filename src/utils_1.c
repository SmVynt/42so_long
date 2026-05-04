/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/26 23:05:45 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clean(t_gs *game)
{
	mlx_t	*mlx;

	mlx = game->mlx;
	if (mlx)
	{
		if (game->screen)
			mlx_delete_image(mlx, game->screen);
		game->screen = NULL;
	}
	ft_destroy_game_textures(game);
	if (mlx)
	{
		mlx_terminate(mlx);
		game->mlx = NULL;
	}
	if (game->enemies)
	{
		free(game->enemies);
		game->enemies = NULL;
	}
	if (game->collects)
	{
		free(game->collects);
		game->collects = NULL;
	}
	ft_free_map(&game->map);
	ft_printf(COLOR_B "Exiting\n" COLOR_X);
	ft_printf("\n");
}

void	ft_exit_error(char *str, t_gs *game)
{
	ft_printf(COLOR_R "Error\n" COLOR_Y);
	perror(str);
	ft_printf("" COLOR_X);
	ft_clean(game);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str, t_gs *game)
{
	ft_printf(COLOR_R "Error\n" COLOR_Y);
	ft_printf("%s" COLOR_X, str);
	ft_clean(game);
	exit(EXIT_FAILURE);
}

void	ft_exit_game(t_gs *game)
{
	ft_clean(game);
	exit(0);
}

char	*ft_strip_from_n(char *str)
{
	char	*new_str;
	int		len;

	len = 0;
	if (!str)
		return (NULL);
	if (str[0] == '\n')
	{
		free(str);
		return (NULL);
	}
	while (str[len] && str[len] != '\n')
		len++;
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str, (len + 1));
	new_str[len] = '\0';
	free(str);
	return (new_str);
}

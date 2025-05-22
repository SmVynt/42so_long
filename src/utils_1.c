/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 01:25:40 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_clean(t_gamestate *game)
{
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->window);
		free(game->mlx);
	}
	if (game->enemies)
		free(game->enemies);
	if (game->collects)
		free(game->collects);
	ft_free_map(&game->map);
}

void	ft_exit_error(char *str, t_gamestate *game)
{
	ft_printf(COLOR_R "Error\n" COLOR_X);
	perror(str);
	ft_clean(game);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str, t_gamestate *game)
{
	ft_printf(COLOR_R "Error\n" COLOR_X);
	ft_printf("%s", str);
	ft_clean(game);
	exit(EXIT_FAILURE);
}

int	ft_exit_game(t_gamestate *game)
{
	// if (game->mlx)
	// {
	// 	mlx_destroy_window(game->mlx, game->window);
	// 	free(game->mlx);
	// }
	// if (game->enemies)
	// 	free(game->enemies);
	// if (game->collects)
	// 	free(game->collects);
	// ft_free_map(&game->map);
	ft_clean(game);
	exit(0);
	return (game->steps);
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

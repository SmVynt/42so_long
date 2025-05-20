/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/21 00:34:42 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_count(t_gamestate *game)
{
	t_vec		v;
	int			steps;

	v.x = game->map.w * TS - game->textures.digits[0].w - TS;
	v.y = game->map.h * TS - (game->textures.digits[0].h + TS) / 2;
	steps = game->steps;
	if (steps == 0)
	{
		ft_override_images(&game->img.fg, &game->textures.digits[0], v, 0);
	}
	else
	{
		while (steps > 0)
		{
			ft_override_images(&game->img.fg,
				&game->textures.digits[steps % 10], v, 0);
			steps /= 10;
			v.x -= game->textures.digits[0].w - 2;
		}
	}
}

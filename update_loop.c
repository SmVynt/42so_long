/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/15 23:38:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_update_state(t_gamestate *game)
{
	if (game->state == STATE_CALC)
	{
		game->state = STATE_IDLE;
		game->turn = 0.0f;
	}
	else if (game->state == STATE_MOVE)
	{
		game->turn = ft_lerp(game->turn, 1.0f, GAME_LERP);
		if(game->turn >= 0.99f)
		{
			game->turn = 1.0f;
			game->state = STATE_CALC;
		}
	}
}

int	ft_update(t_gamestate *game)
{
	ft_update_state(game);
	ft_update_enemies(game);
	ft_update_hero(game);
	ft_override_images(&game->img.render_sm, &game->img.bg, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.en, mk_vec(0, 0), 0);
	ft_cover_images(&game->img.render_sm, &game->img.fg, mk_vec(0, 0), 0);
	ft_scale_image_ca(&game->img.render_sm, &game->img.render);
	mlx_put_image_to_window(game->mlx, game->window,
		game->img.render.src, 0, 0);
	return (0);
}

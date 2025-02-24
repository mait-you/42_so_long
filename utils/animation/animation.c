/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:47:26 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/23 17:22:31 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	enemy_animation(t_game *game)
{
	if (game->enmy->frame_count++ >= ANIMATION_SPEED)
	{
		game->enmy->current_frame
			= (game->enmy->current_frame + 1) % MAX_FRAME;
		game->enmy->frame_count = 0;
	}
}

static void	player_animation(t_game *game)
{
	if (game->player->frame_count++ >= ANIMATION_SPEED)
	{
		game->player->current_frame
			= (game->player->current_frame + 1) % MAX_FRAME;
		game->player->frame_count = 0;
	}
}

static void	coin_animation(t_game *game)
{
	if (game->coin->frame_count++ >= ANIMATION_SPEED)
	{
		game->coin->current_frame
			= (game->coin->current_frame + 1) % (MAX_FRAME + 2);
		game->coin->frame_count = 0;
	}
}

static void	exit_animation(t_game *game)
{
	if (game->exit->current_frame == 2)
		return ;
	if (game->exit->frame_count++ >= ANIMATION_SPEED)
	{
		game->exit->current_frame
			= (game->exit->current_frame + 1) % (MAX_FRAME - 1);
		game->exit->frame_count = 0;
	}
}

void	update_animation(t_game *game)
{
	player_animation(game);
	enemy_animation(game);
	coin_animation(game);
	if (game->player->player_coins == game->coin->coins)
		exit_animation(game);
}

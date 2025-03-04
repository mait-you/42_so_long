/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:47:26 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:04:30 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	enemy_animation(t_game *game)
{
	if (game->enemy_frame_timer++ >= ANIMATION_SPEED)
	{
		game->enemy_current_frame
			= (game->enemy_current_frame + 1) % 4;
		game->enemy_frame_timer = 0;
	}
}

static void	player_animation(t_player *player)
{
	if (player->frame_timer++ >= ANIMATION_SPEED)
	{
		player->current_frame
			= (player->current_frame + 1) % 4;
		player->frame_timer = 0;
	}
}

static void	coin_animation(t_coin *coin)
{
	if (coin->frame_timer++ >= ANIMATION_SPEED)
	{
		coin->current_frame
			= (coin->current_frame + 1) % 6;
		coin->frame_timer = 0;
	}
}

static void	exit_animation(t_exit *exit)
{
	if (exit->current_frame == 2)
		return ;
	if (exit->frame_timer++ >= ANIMATION_SPEED)
	{
		exit->current_frame
			= (exit->current_frame + 1) % 3;
		exit->frame_timer = 0;
	}
}

void	update_animation(t_game *game)
{
	player_animation(game->player);
	enemy_animation(game);
	coin_animation(game->coin);
	update_enemies(game);
	if (game->player->player_coins == game->coin->coin_count)
		exit_animation(game->exit);
}

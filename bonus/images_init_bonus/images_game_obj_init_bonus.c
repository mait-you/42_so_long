/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_game_obj_init_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/01 11:56:17 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	init_numbers(t_game *game)
{
	char	*number_paths_5[6];
	char	*number_paths_9[6];

	number_paths_5[0] = "./textures/numbers/0.xpm";
	number_paths_5[1] = "./textures/numbers/1.xpm";
	number_paths_5[2] = "./textures/numbers/2.xpm";
	number_paths_5[3] = "./textures/numbers/3.xpm";
	number_paths_5[4] = "./textures/numbers/4.xpm";
	number_paths_5[5] = NULL;
	number_paths_9[0] = "./textures/numbers/5.xpm";
	number_paths_9[1] = "./textures/numbers/6.xpm";
	number_paths_9[2] = "./textures/numbers/7.xpm";
	number_paths_9[3] = "./textures/numbers/8.xpm";
	number_paths_9[4] = "./textures/numbers/9.xpm";
	number_paths_9[5] = NULL;
	init_image_array(game, number_paths_5, game->numbers_textures_5, 6);
	init_image_array(game, number_paths_9, game->numbers_textures_9, 6);
	return (0);
}

static int	init_text(t_game *game)
{
	char	*text[7];

	text[0] = "./textures/letters/m.xpm";
	text[1] = "./textures/letters/o.xpm";
	text[2] = "./textures/letters/v.xpm";
	text[3] = "./textures/letters/e.xpm";
	text[4] = "./textures/letters/s.xpm";
	text[5] = "./textures/letters/d_c.xpm";
	text[6] = NULL;
	init_image_array(game, text, game->txt_texture, 7);
	return (init_numbers(game));
}

void	init_game_objects(t_game *game)
{
	char	*coin_frames[7];
	char	*exit_frames[4];
	char	*enemy_frames[5];

	coin_frames[0] = "./textures/coins/frame1.xpm";
	coin_frames[1] = "./textures/coins/frame2.xpm";
	coin_frames[2] = "./textures/coins/frame3.xpm";
	coin_frames[3] = "./textures/coins/frame4.xpm";
	coin_frames[4] = "./textures/coins/frame5.xpm";
	coin_frames[5] = "./textures/coins/frame6.xpm";
	coin_frames[6] = NULL;
	exit_frames[0] = "./textures/exit/frame1.xpm";
	exit_frames[1] = "./textures/exit/frame2.xpm";
	exit_frames[2] = "./textures/exit/frame3.xpm";
	exit_frames[3] = NULL;
	enemy_frames[0] = "./textures/enemy/frame1.xpm";
	enemy_frames[1] = "./textures/enemy/frame2.xpm";
	enemy_frames[2] = "./textures/enemy/frame3.xpm";
	enemy_frames[3] = "./textures/enemy/frame4.xpm";
	enemy_frames[4] = NULL;
	init_image_array(game, coin_frames, game->coin->coins_frames, 7);
	init_image_array(game, exit_frames, game->exit->exit_frames, 4);
	init_image_array(game, enemy_frames, game->enemys_frames, 5);
	init_text(game);
}

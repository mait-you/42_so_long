/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_game_obj_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 17:06:39 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	init_numbers(t_game *game)
{
	char	*number_paths[11];

	number_paths[0] = "./textures/numbers/0.xpm";
	number_paths[1] = "./textures/numbers/1.xpm";
	number_paths[2] = "./textures/numbers/2.xpm";
	number_paths[3] = "./textures/numbers/3.xpm";
	number_paths[4] = "./textures/numbers/4.xpm";
	number_paths[5] = "./textures/numbers/5.xpm";
	number_paths[6] = "./textures/numbers/6.xpm";
	number_paths[7] = "./textures/numbers/7.xpm";
	number_paths[8] = "./textures/numbers/8.xpm";
	number_paths[9] = "./textures/numbers/9.xpm";
	number_paths[10] = NULL;
	init_image_array(game, number_paths, game->numbers_textures, 10);
	return (0);
}

static int	init_text(t_game *game)
{
	char	*text[8];

	text[0] = "./textures/letters/m.xpm";
	text[1] = "./textures/letters/o.xpm";
	text[2] = "./textures/letters/v.xpm";
	text[3] = "./textures/letters/e.xpm";
	text[4] = "./textures/letters/s.xpm";
	text[5] = "./textures/letters/d_c.xpm";
	text[6] = "./textures/letters/b_s.xpm";
	text[7] = NULL;
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
	init_image_array(game, enemy_frames, game->enmy->enemys_frames, 5);
	init_text(game);
}

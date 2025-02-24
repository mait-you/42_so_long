/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:25:13 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/23 18:14:55 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	destroy_player_images(t_game *game)
{
	int	i;

	if (!game->player)
		return ;
	i = -1;
	while (++i < 5)
	{
		if (game->player->player_go_right_frames[i])
			mlx_destroy_image
			(game->mlx_ptr, game->player->player_go_right_frames[i]);
		if (game->player->player_go_left_frames[i])
			mlx_destroy_image
			(game->mlx_ptr, game->player->player_go_left_frames[i]);
		if (game->player->player_go_up_frames[i])
			mlx_destroy_image
			(game->mlx_ptr, game->player->player_go_up_frames[i]);
		if (game->player->player_go_down_frames[i])
			mlx_destroy_image
			(game->mlx_ptr, game->player->player_go_down_frames[i]);
	}
}

static void	destroy_all_images(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 10)
		if (game->numbers_textures[i])
			mlx_destroy_image(game->mlx_ptr, game->numbers_textures[i]);
	i = -1;
	while (++i < 7)
		if (game->txt_texture[i])
			mlx_destroy_image(game->mlx_ptr, game->txt_texture[i]);
	if (game->map)
	{
		if (game->map->_0_img)
			mlx_destroy_image(game->mlx_ptr, game->map->_0_img);
		if (game->map->_1_img)
			mlx_destroy_image(game->mlx_ptr, game->map->_1_img);
	}
}

void	destroy_images(t_game *game)
{
	int	i;

	if (!game || !game->mlx_ptr)
		return ;
	destroy_all_images(game);
	destroy_player_images(game);
	i = -1;
	while (++i < 8)
		if (game->coin && game->coin->coins_frames[i])
			mlx_destroy_image(game->mlx_ptr, game->coin->coins_frames[i]);
	i = -1;
	while (++i < 5)
	{
		if (game->enmy && game->enmy->enemys_frames[i])
			mlx_destroy_image(game->mlx_ptr, game->enmy->enemys_frames[i]);
		if (game->exit && game->exit->exit_frames[i])
			mlx_destroy_image(game->mlx_ptr, game->exit->exit_frames[i]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:25:13 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/26 17:29:00 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_game *game)
{
	if (!game || !game->mlx_ptr)
		return ;
	if (game->player && game->player->player_frames)
		mlx_destroy_image(game->mlx_ptr, game->player->player_frames);
	if (game->map && game->map->_0_img)
		mlx_destroy_image(game->mlx_ptr, game->map->_0_img);
	if (game->map && game->map->_1_img)
		mlx_destroy_image(game->mlx_ptr, game->map->_1_img);
	if (game->coins_frames)
		mlx_destroy_image(game->mlx_ptr, game->coins_frames);
	if (game->exit_frames)
		mlx_destroy_image(game->mlx_ptr, game->exit_frames);
}

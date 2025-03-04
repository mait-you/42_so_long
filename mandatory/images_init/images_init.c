/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/01 08:44:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*load_xpm(t_game *game, char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	if (!img)
		error_cleanup(game, "Failed to load texture");
	return (img);
}

int	imgs_initialize(t_game *game)
{
	int	width;
	int	height;

	game->map->_0_img = load_xpm
		(game, "./textures/floor/floor_2_64.xpm", &width, &height);
	game->map->_1_img = load_xpm
		(game, "./textures/floor/floor_1_64.xpm", &width, &height);
	game->coins_frames = load_xpm
		(game, "./textures/coins/frame3.xpm", &width, &height);
	game->player->player_frames = load_xpm
		(game, "./textures/player/frame1.xpm", &width, &height);
	game->exit_frames = load_xpm
		(game, "./textures/exit/frame2.xpm", &width, &height);
	return (0);
}

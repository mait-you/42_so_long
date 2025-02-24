/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_player_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:05:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 17:06:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*load_xpm(t_game *game, char *path, int *width, int *height)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	if (!img)
		error_cleanup(game, "Failed to load texture");
	return (img);
}

void	init_image_array(t_game *game, char **paths, void *frames[], int size)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < size)
	{
		if (paths[i])
			frames[i] = load_xpm(game, paths[i], &width, &height);
		i++;
	}
}

static int	init_player_left_up(t_game *game)
{
	char	*left_frames[5];
	char	*up_frames[5];

	left_frames[0] = "./textures/player/frame1_l.xpm";
	left_frames[1] = "./textures/player/frame2_l.xpm";
	left_frames[2] = "./textures/player/frame3_l.xpm";
	left_frames[3] = "./textures/player/frame4_l.xpm";
	left_frames[4] = NULL;
	up_frames[0] = "./textures/player/frame1_u.xpm";
	up_frames[1] = "./textures/player/frame2_u.xpm";
	up_frames[2] = "./textures/player/frame3_u.xpm";
	up_frames[3] = "./textures/player/frame4_u.xpm";
	up_frames[4] = NULL;
	init_image_array(game, left_frames, game->player->player_go_left_frames, 5);
	init_image_array(game, up_frames, game->player->player_go_up_frames, 5);
	return (0);
}

static int	init_player_down_right(t_game *game)
{
	char	*right_frames[5];
	char	*down_frames[5];

	right_frames[0] = "./textures/player/frame1_r.xpm";
	right_frames[1] = "./textures/player/frame2_r.xpm";
	right_frames[2] = "./textures/player/frame3_r.xpm";
	right_frames[3] = "./textures/player/frame4_r.xpm";
	right_frames[4] = NULL;
	down_frames[0] = "./textures/player/frame1.xpm";
	down_frames[1] = "./textures/player/frame2.xpm";
	down_frames[2] = "./textures/player/frame3.xpm";
	down_frames[3] = "./textures/player/frame4.xpm";
	down_frames[4] = NULL;
	game->player->current_pos = 'D';
	init_image_array
	(game, down_frames, game->player->player_go_down_frames, 5);
	init_image_array
	(game, right_frames, game->player->player_go_right_frames, 5);
	return (init_player_left_up(game));
}

int	imgs_initialize(t_game *game)
{
	int	width;
	int	height;

	game->map->_0_img = load_xpm
		(game, "./textures/floor/floor_2_64.xpm", &width, &height);
	game->map->_1_img = load_xpm
		(game, "./textures/floor/floor_1_64.xpm", &width, &height);
	init_player_down_right(game);
	init_game_objects(game);
	return (0);
}

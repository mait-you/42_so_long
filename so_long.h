/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:27:11 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 19:32:09 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx.h> 
# include <fcntl.h>

# define XK_a				0
# define XK_Left			123
# define XK_d				2
# define XK_Right			124
# define XK_w				13
# define XK_Up				126
# define XK_s				1
# define XK_Down			125
# define XK_Escape			53
# define KeyPress			2
# define DestroyNotify		17
# define KeyPressMask		(1L<<0)
# define NoEventMask		0

# define BLOCK				64
# define MAX_FRAME			4
# define ANIMATION_SPEED	10
# define TITLE				"so_long"

typedef struct s_enemy
{
	int			enemys;
	void		*enemys_frames[5];
	int			current_frame;
	int			frame_count;
}				t_enemy;

typedef struct s_exit
{
	int			exits;
	void		*exit_frames[5];
	int			current_frame;
	int			frame_count;
}				t_exit;

typedef struct s_coin
{
	int			coins;
	void		*coins_frames[8];
	int			current_frame;
	int			frame_count;
}				t_coin;

typedef struct s_player
{
	int			players;
	void		*player_go_right_frames[5];
	void		*player_go_left_frames[5];
	void		*player_go_up_frames[5];
	void		*player_go_down_frames[5];
	int			current_frame;
	char		current_pos;
	int			frame_count;
	int			x_pos;
	int			y_pos;
	int			player_coins;
	int			moves;
}				t_player;

typedef struct s_map
{
	int			map_fd;
	char		**map_str;
	int			map_row;
	int			map_col;
	void		*_0_img;
	void		*_1_img;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*numbers_textures[10];
	void		*txt_texture[8];
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_exit		*exit;
	t_enemy		*enmy;
}				t_game;

int		chek_args(int ac, char *file_path);
t_game	*game_initialize(char *file_path);
int	imgs_initialize(t_game *game);
void	init_image_array(t_game *game, char **paths, void *frames[], int size);

void	init_game_objects(t_game *game);
void	error_cleanup(t_game *game, char *error_msg);
int	get_map(t_game *game, char *file_path);
int	flood_fill_chek(t_game *game, t_map	*map);
void	args_free(char **ptr);
int	control_moves(int keysym, t_game *game, int x, int y);
void	exit_prog(t_game *game, int _exit);
int	player_win(t_game *game);
int	player_lose(t_game *game);
void	update_animation(t_game *game);
int	load_map(t_game *game);
int	ft_texturnbr(t_game *game, int nb, int block);
void	destroy_images(t_game *game);

#endif

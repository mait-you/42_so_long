/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:27:11 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:25:44 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

# ifndef BLOCK
#  define BLOCK				64
# endif
# ifndef ANIMATION_SPEED
#  define ANIMATION_SPEED	10
# endif
# ifndef TITLE
#  define TITLE				"so_long"
# endif

typedef struct s_enemy
{
	int			x_pos;
	int			y_pos;
	int			direction;
	int			patrol_range;
	int			initial_x;
}				t_enemy;

typedef struct s_exit
{
	int			exit_count;
	void		*exit_frames[4];
	int			current_frame;
	int			frame_timer;
}				t_exit;

typedef struct s_coin
{
	int			coin_count;
	void		*coins_frames[7];
	int			current_frame;
	int			frame_timer;
}				t_coin;

typedef struct s_player
{
	int			player_count;
	void		*player_go_right_frames[5];
	void		*player_go_left_frames[5];
	void		*player_go_up_frames[5];
	void		*player_go_down_frames[5];
	int			current_frame;
	char		current_pos;
	int			frame_timer;
	int			x_pos;
	int			y_pos;
	int			player_coins;
	int			moves;
}				t_player;

typedef struct s_map
{
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
	void		*numbers_textures_5[6];
	void		*numbers_textures_9[6];
	void		*txt_texture[7];
	t_map		*map;
	t_player	*player;
	t_coin		*coin;
	t_exit		*exit;
	void		*enemys_frames[5];
	int			enemy_count;
	int			enemy_current_frame;
	int			enemy_frame_timer;
	t_enemy		**enemies;
}				t_game;

int		check_args(int ac, char *file_path);
void	game_initialize(t_game *game, char *file_path);
int		imgs_initialize(t_game *game);
void	init_image_array(t_game *game, char **paths, void *frames[], int size);
void	init_game_objects(t_game *game);
void	error_cleanup(t_game *game, char *error_msg);
int		get_map(t_game *game, char *file_path);
int		flood_fill_check(t_game *game, t_map *map);
void	args_free(char **ptr);
int		control_moves(int keycode, t_game *game, int x, int y);
void	exit_prog(t_game *game, int _exit);
int		player_win(t_game *game);
int		player_lose(t_game *game);
void	update_animation(t_game *game);
int		load_map(t_game *game);
int		ft_texturnbr(t_game *game, int nb, int block);
void	destroy_images(t_game *game);
int		get_player_position(t_game *game);
int		get_enemy(t_game *game);
void	update_enemies(t_game *game);
int		is_player_lose_or_win(t_game *game);

#endif

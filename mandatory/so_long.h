/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:27:11 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:25:53 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

# ifndef BLOCK
#  define BLOCK	64
# endif

# ifndef TITLE
#  define TITLE	"so_long"
# endif

typedef struct s_player
{
	int			players;
	int			x_pos;
	int			y_pos;
	int			moves;
	int			player_coins;
	void		*player_frames;

}				t_player;

typedef struct s_map
{
	int			map_row;
	int			map_col;
	void		*_0_img;
	void		*_1_img;
	char		**map_str;
}				t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			coins;
	int			exit;
	void		*coins_frames;
	void		*exit_frames;
	t_map		*map;
	t_player	*player;
}				t_game;

int		check_args(int ac, char *file_path);
void	game_initialize(t_game *game, t_map *map, \
t_player *player, char *file_path);
int		imgs_initialize(t_game *game);
void	error_cleanup(t_game *game, char *error_msg);
int		get_map(t_game *game, char *file_path);
int		flood_fill_check(t_game *game, t_map	*map);
void	args_free(char **ptr);
int		control_moves(int keycode, t_game *game, int x, int y);
void	exit_prog(t_game *game, int _exit);
int		player_win(t_game *game);
int		player_lose(t_game *game);
void	update_animation(t_game *game);
int		load_map(t_game *game);
void	destroy_images(t_game *game);

#endif

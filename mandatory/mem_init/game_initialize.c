/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:10:05 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/01 11:58:24 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static size_t	count_line(char *file_path)
{
	char	*line;
	int		fd;
	size_t	line_count;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_cleanup(NULL, "Open failed");
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static void	mlx_and_win_initialize(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_cleanup(game, "MLX init failed");
	game->win_ptr = mlx_new_window
		(
			game->mlx_ptr,
			BLOCK * game->map->map_col,
			BLOCK * game->map->map_row,
			TITLE
			);
	if (!game->win_ptr)
		error_cleanup(game, "Failed to create window");
}

void	game_initialize(
	t_game *game, t_map *map, t_player *player, char *file_path
	)
{
	ft_memset(map, 0, sizeof(t_map));
	ft_memset(player, 0, sizeof(t_player));
	ft_memset(game, 0, sizeof(t_game));
	game->map = map;
	game->player = player;
	game->map->map_str
		= (char **)ft_calloc(count_line(file_path) + 1, sizeof(char *));
	if (!game->map)
		error_cleanup(game, "alloction failed");
	get_map(game, file_path);
	mlx_and_win_initialize(game);
}

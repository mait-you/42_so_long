/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:29:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 16:27:37 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	chek_character(t_game *game, t_map *map, int i, int j)
{
	i = 0;
	while (map->map_str[i])
	{
		j = 0;
		while (map->map_str[i][j])
		{
			if (!ft_strchr("01PCE", map->map_str[i][j]))
				error_cleanup(game, "Map contains invalid characters");
			if (map->map_str[i][j] == 'P')
				game->player->players++;
			if (map->map_str[i][j] == 'C')
				game->coins++;
			if (map->map_str[i][j] == 'E')
				game->exit++;
			j++;
		}
		i++;
	}
	if (game->player->players != 1 || game->exit != 1
		|| game->coins < 1)
		error_cleanup
		(game, "Map must have one 'P', one 'E', and at least 1 'C'");
	return (0);
}

static int	chek_len(t_game *game, t_map *map)
{
	int		i;
	int		j;
	size_t	len_chek;

	i = 0;
	len_chek = ft_strlen(map->map_str[i]);
	while (map->map_str[i])
	{
		if (ft_strlen(map->map_str[i]) != len_chek)
			error_cleanup(game, "All rows must have equal length");
		if (map->map_str[i][0] != '1')
			error_cleanup(game, "Left border must be walls");
		if (map->map_str[i][map->map_col - 1] != '1')
			error_cleanup(game, "Right border must be walls");
		i++;
	}
	j = 0;
	while (map->map_str[0][j])
		if (map->map_str[0][j++] != '1')
			error_cleanup(game, "Top border must be walls");
	j = 0;
	while (map->map_str[i - 1][j])
		if (map->map_str[i - 1][j++] != '1')
			error_cleanup(game, "Bottom border must be walls");
	return (0);
}

static int	chek_rectangular(t_game *game, t_map *map)
{
	if (map->map_row < 3)
		error_cleanup(game, "Map height must be at least 3 rows");
	if (map->map_col > 128)
		error_cleanup(game, "Map width cannot exceed 128 columns");
	if (map->map_row >= map->map_col)
		error_cleanup(game, "Map is not rectangular enough");
	return (0);
}

static int	chek_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map_str[y])
	{
		x = 0;
		while (map->map_str[y][x])
		{
			if (map->map_str[y][x] == 'P')
			{
				game->player->x_pos = x;
				game->player->y_pos = y;
			}
			x++;
		}
		y++;
	}
	map->map_row = y;
	map->map_col = (int)ft_strlen(map->map_str[0]);
	chek_rectangular(game, map);
	chek_len(game, map);
	chek_character(game, map, 0, 0);
	flood_fill_check(game, map);
	return (0);
}

int	get_map(t_game *game, char *file_path)
{
	t_map	*map;
	int		i;
	int		fd;

	i = 0;
	map = game->map;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_cleanup(game, "Open failed");
	map->map_str[i] = get_next_line(fd);
	if (!map->map_str[i])
	{
		close(fd);
		error_cleanup(game, "File is empty");
	}
	while (map->map_str[i++] != NULL)
		map->map_str[i] = get_next_line(fd);
	close(fd);
	i = -1;
	while (map->map_str[++i])
		map->map_str[i][ft_strcspn(map->map_str[i], "\n")] = 0;
	return (chek_map(game, map));
}

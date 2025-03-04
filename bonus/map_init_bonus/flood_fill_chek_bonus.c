/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_chek_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:34:10 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:20:53 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	chak_fill_map(t_game *game, char **tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (ft_strchr("PCE", tmp_map[i][j]))
			{
				args_free(tmp_map);
				error_cleanup
				(game, "Not all items are reachable by the player");
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill(t_map *map, char **tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || y > map->map_row || x > map->map_col \
		|| tmp_map[y][x] == '1')
		return (0);
	tmp_map[y][x] = '1';
	fill(map, tmp_map, x + 1, y);
	fill(map, tmp_map, x - 1, y);
	fill(map, tmp_map, x, y + 1);
	fill(map, tmp_map, x, y - 1);
	return (0);
}

static int	copy_map(t_game *game, char ***tmp_map)
{
	int		i;

	i = 0;
	while (game->map->map_str[i])
	{
		(*tmp_map)[i] = ft_strdup(game->map->map_str[i]);
		if (!(*tmp_map)[i])
		{
			args_free(*tmp_map);
			error_cleanup(game, "Memory allocation failed");
		}
		i++;
	}
	(*tmp_map)[i] = NULL;
	return (0);
}

int	flood_fill_check(t_game *game, t_map	*map)
{
	char	**tmp_map;

	tmp_map = (char **)ft_calloc(map->map_row + 1, sizeof(char *));
	if (!tmp_map)
		error_cleanup(game, "Memory allocation failed");
	copy_map(game, &tmp_map);
	fill
	(map, tmp_map, game->player->x_pos, game->player->y_pos);
	chak_fill_map(game, tmp_map);
	args_free(tmp_map);
	return (0);
}

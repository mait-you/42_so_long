/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/01 11:53:48 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	enemies_free(t_enemy **enemies)
{
	int	i;

	if (!enemies)
		return ;
	i = 0;
	while (enemies[i])
	{
		free(enemies[i]);
		i++;
	}
	free(enemies);
}

static void	game_free(t_game *game)
{
	if (!game)
		return ;
	destroy_images(game);
	if (game->map)
	{
		if (game->map->map_str)
			args_free(game->map->map_str);
	}
	if (game->enemies)
		enemies_free(game->enemies);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
}

void	args_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	error_cleanup(t_game *game, char *error_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	exit_prog(game, 1);
}

void	exit_prog(t_game *game, int _exit)
{
	game_free(game);
	exit(_exit);
}

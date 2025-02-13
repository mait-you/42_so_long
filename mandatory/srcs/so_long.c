/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:24:49 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/13 10:40:21 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;

	// make connection to the correct graphical system 
	mlx_ptr = mlx_init();
	// create window
	mlx_win = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, TITLE);
	img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	mlx_loop(mlx_ptr);
    return (0);
}

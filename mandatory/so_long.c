/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 13:46:01 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_key(int	key, t_data	data)
{
	if (key == 27)
		mlx_destroy_window(data.mlx, data.mlx_win);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_res	res;

	parce_in(ac, av);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (EXIT_FAILURE);
	mlx_new_window(data.mlx, 1920, 1080, TILTEL);
	mlx_key_hook(data.mlx_win, esc_key, &data);
	// data.wall = mlx_xpm_to_image(data.mlx, "textures/brick.xpm", &res.with, &res.height);
	// if (!data.wall)
	// 	return (EXIT_FAILURE);
	mlx_loop(data.mlx);
}

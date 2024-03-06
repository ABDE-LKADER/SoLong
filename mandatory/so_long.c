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
	if (key == 17)
	{
		mlx_destroy_window(data.mlx, data.mlx_win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	res;
	t_img	img;
	t_data	data;

	mlx_parce_input(ac, av, &res);
	exit(0);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, res.width * 120, res.height * 120, TILTEL);
	if (!data.mlx_win)
		return (EXIT_FAILURE);
	mlx_key_hook(data.mlx_win, esc_key, &data);
	img.wall = mlx_xpm_file_to_image(data.mlx, "textures/brick.xpm", &img.width, &img.height);
	if (!img.wall)
		return (EXIT_FAILURE);
	int	i = 0;
	int	j = 16;
	while (j--)
	{
		mlx_put_image_to_window(data.mlx, data.mlx_win, img.wall, i, 480);
		i += 120;
	}
	mlx_loop(data.mlx);
}

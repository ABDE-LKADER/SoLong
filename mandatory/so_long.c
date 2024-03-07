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

static void	free_all(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	esc_key(int	key, t_data	data)
{
	if (key)
	{
		mlx_destroy_window(data.mlx, data.mlx_win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_img	img;
	t_data	data;

	mlx_parce_input(ac, av, &map);
	// free_all(map.map);
	// exit(0);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(map.map), EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, map.width * 120, map.height * 120, TILTEL);
	if (!data.mlx_win)
		return (free_all(map.map), EXIT_FAILURE);
	mlx_key_hook(data.mlx_win, esc_key, &data);
	mlx_hook(data.mlx_win, 17, 0, esc_key, &data);
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

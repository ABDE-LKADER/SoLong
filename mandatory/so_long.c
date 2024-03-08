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

int	destroy_notify(int	key, t_data	data)
{
	mlx_destroy_window(data.mlx, data.mlx_win);
	return (exit(0), 0);
}

int	esc_key(int	key, t_data	data)
{
	if (key)
		mlx_destroy_window(data.mlx, data.mlx_win);
	return (exit(0), 0);
}

static void	mlx_render_window(t_data *data, t_map *map, t_img *img)	
{
	img->wall = mlx_xpm_file_to_image(data->mlx, "textures/brick.xpm", &img->width, &img->height);
	if (!img->wall)
		return (EXIT_FAILURE);
	int	i = 0;
	int	j = 16;
	while (j--)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, img->wall, i, 480);
		i += 120;
	}	
}

int	main(int ac, char **av)
{
	t_map	map;
	t_img	img;
	t_data	data;

	mlx_parce_input(ac, av, &map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(map.map), EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, map.width * 120, map.height * 120, TILTEL);
	if (!data.mlx_win)
		return (free_all(map.map), EXIT_FAILURE);
	mlx_key_hook(data.mlx_win, esc_key, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_notify, &data);
	mlx_render_window(&data, &map, &img);
	mlx_loop(data.mlx);
}

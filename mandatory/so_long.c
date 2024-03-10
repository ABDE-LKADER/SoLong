/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/10 21:36:52 by abadouab         ###   ########.fr       */
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

int	destroy_notify(t_data	*data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (exit(0), 0);
}

int	esc_key(int	key, t_data	*data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0); 
	}
	return (0);
}

static void	mlx_render_space(t_data *data)	
{
	int		y;
	int		x;

	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->img.width, &data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND, &data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, &data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->img.width, &data->img.height);
	data->img.collect = mlx_xpm_file_to_image(data->mlx, COLLECT, &data->img.width, &data->img.height);
	if (!data->img.wall)
		return ;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall, (x * 60), (y * 60));
			else if (data->map.map[y][x] == '0' || data->map.map[y][x] == 'P'
				|| data->map.map[y][x] == 'E' || data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ground, (x * 60), (y * 60));
			if (data->map.map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player, (x * 60), (y * 60));
			else if (data->map.map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit, (x * 60), (y * 60));
			else if (data->map.map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.collect, (x * 60) + 15, (y * 60) + 15);
			x++;
		}
		y++;
	}	
}

int	main(int ac, char **av)
{
	t_data	data;

	mlx_parce_input(ac, av, &data.map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(data.map.map), EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, data.map.width * 60, data.map.height * 60, TILTEL);
	if (!data.mlx_win)
		return (free_all(data.map.map), EXIT_FAILURE);
	mlx_hook(data.mlx_win, 2, 0, esc_key, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_notify, &data);
	mlx_render_space(&data);
	mlx_loop(data.mlx);
}

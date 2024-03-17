/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/17 08:56:24 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	mlx_init_img(t_data	*data)
{
	t_img	*img;

	img = &data->img;
	img->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&img->width, &img->height);
	img->wall2 = mlx_xpm_file_to_image(data->mlx, WALL2,
			&img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&img->width, &img->height);
	img->ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img->width, &img->height);
	if (!img->wall || !img->ground || !img->wall2 || !img->player
		|| !img->exit || !img->collect)
		return (1);
	return (0);
}

void	mlx_put_img(t_data *data, int x, int y, int set)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ground,
		(x * DIMO), (y * DIMO));
	if (set && data->map.map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall,
			(x * DIMO), (y * DIMO));
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit,
			x * DIMO, y * DIMO);
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player,
			x * DIMO, y * DIMO);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.collect,
			x * DIMO, y * DIMO);
}

static void	mlx_game_render(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
			mlx_put_img(data, x, y, TRUE);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	mlx_parce_input(ac, av, &data.map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (cleanup(data.map.map, NULL), EXIT_FAILURE);
	data.mlx_win = mlx_new_window(data.mlx, data.map.width * DIMO,
			data.map.height * DIMO, TILTEL);
	if (!data.mlx_win)
		return (cleanup(data.map.map, NULL), EXIT_FAILURE);
	mlx_hook(data.mlx_win, 2, 0, mlx_move_player, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_notify, &data);
	if (mlx_init_img(&data))
	{
		cleanup(data.map.map, &data);
		mlx_message_error(3);
	}
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}

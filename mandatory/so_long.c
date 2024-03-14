/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/14 11:32:05 by abadouab         ###   ########.fr       */
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
	img->p_left = mlx_xpm_file_to_image(data->mlx, P_LEFT,
			&img->width, &img->height);
	img->p_right = mlx_xpm_file_to_image(data->mlx, P_RIGHT,
			&img->width, &img->height);
	img->ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img->width, &img->height);
	if (!img->wall || !img->ground || !img->wall2 || !img->p_left
		|| !img->p_right || !img->exit || !img->collect)
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
	// if (set && data->map.map[y][x] == '1' && (data->map.height - 1 == y || !y))
	// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall,
	// 		(x * DIMO), (y * DIMO));
	// else if (set && data->map.map[y][x] == '1' && (data->map.width - 1 == x || !x))
	// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall2,
	// 		(x * DIMO), (y * DIMO));
	// if (set && ft_strchr("0PEC", data->map.map[y][x]))
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit,
			(x * DIMO) + 20, (y * DIMO) + 24);
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.p_right,
			(x * DIMO), (y * DIMO) - 10);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.collect,
			(x * DIMO) + 35, (y * DIMO) + 38);
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

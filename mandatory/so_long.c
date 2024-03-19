/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/19 11:45:59 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	mlx_init_img(t_data	*data)
{
	t_img	*img;

	img = &data->img;
	img->wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&img->width, &img->height);
	img->wall0 = mlx_xpm_file_to_image(data->mlx, WALL0,
			&img->width, &img->height);
	img->wall2 = mlx_xpm_file_to_image(data->mlx, WALL2,
			&img->width, &img->height);
	img->wall_e = mlx_xpm_file_to_image(data->mlx, WALL_E,
			&img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&img->width, &img->height);
	img->ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&img->width, &img->height);
	img->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&img->width, &img->height);
	img->wall_l = mlx_xpm_file_to_image(data->mlx, WALL_L,
			&img->width, &img->height);
	img->wall_r = mlx_xpm_file_to_image(data->mlx, WALL_R,
			&img->width, &img->height);
	img->wall_u = mlx_xpm_file_to_image(data->mlx, WALL_U,
			&img->width, &img->height);
	img->wall_d = mlx_xpm_file_to_image(data->mlx, WALL_D,
			&img->width, &img->height);
	img->wall_dl = mlx_xpm_file_to_image(data->mlx, WALL_DL,
			&img->width, &img->height);
	img->wall_ul = mlx_xpm_file_to_image(data->mlx, WALL_UL,
			&img->width, &img->height);
	img->wall_dr = mlx_xpm_file_to_image(data->mlx, WALL_DR,
			&img->width, &img->height);
	img->wall_ur = mlx_xpm_file_to_image(data->mlx, WALL_UR,
			&img->width, &img->height);
	img->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img->width, &img->height);
	// if (!img->wall || !img->ground || !img->player
	// 	|| !img->exit || !img->collect)
	// 	return (1);
	return (0);
}

void	set_wall(t_data *data, int x, int y)
{
	if (!x && !y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_ul,
			x * DIMO, y * DIMO);
	else if (!x && y && data->map.height - 1 != y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_l,
			x * DIMO, y * DIMO);
	else if (!x && data->map.height - 1 == y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_dl,
			x * DIMO, y * DIMO);
	else if (!y && data->map.width - 1 == x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_ur,
			x * DIMO, y * DIMO);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_dr,
			x * DIMO, y * DIMO);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_r,
			x * DIMO, y * DIMO);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_d,
			x * DIMO, y * DIMO);
	else if (x && !y && data->map.width - 1 != x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_u,
			x * DIMO, y * DIMO);
	else if (y - 1 && (data->map.map[y - 1][x] != '1' || data->map.map[y + 1][x] != '1'))
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall,
			x * DIMO, y * DIMO);
	else if (y >= data->map.height / 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall2,
			x * DIMO, y * DIMO);
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall0,
			x * DIMO, y * DIMO);
		if (!(y - 1))
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall_e,
				x * DIMO, y * DIMO);
	}
}

void	mlx_put_img(t_data *data, int x, int y, int set)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ground,
		(x * DIMO), (y * DIMO));
	if (set && data->map.map[y][x] == '1')
		set_wall(data, x, y);
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

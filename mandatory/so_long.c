/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:58 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_ground(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.ground,
		(x * DM), (y * DM));
}

int		set_exit(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit[E0],
		data->exit_x * DM, (data->exit_y * DM));
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit[E6],
		data->exit_x * DM, data->exit_y * DM);
	return (1);
}

int		set_wall(t_data *data, int x, int y)
{
	if (!x && !y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[UL],
			x * DM, y * DM);
	else if (!x && y && data->map.height - 1 != y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WL],
			x * DM, y * DM);
	else if (!x && data->map.height - 1 == y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[DL],
			x * DM, y * DM);
	else if (!y && data->map.width - 1 == x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[UR],
			x * DM, y * DM);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[DR],
			x * DM, y * DM);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WR],
			x * DM, y * DM);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WD],
			x * DM, y * DM);
	else if (x && !y && data->map.width - 1 != x)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WU],
			x * DM, y * DM);
	else if (y - 1 && (data->map.map[y - 1][x] != '1' || data->map.map[y + 1][x] != '1'))
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WA],
			x * DM, y * DM);
	else if (y >= data->map.height / 2)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[W2],
			x * DM, y * DM);
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[W0],
			x * DM, y * DM);
		if (!(y - 1))
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.wall[WE],
				(x * DM) + 5, y * DM);
	}
	return (1);
}

void	mlx_put_img(t_data *data, int x, int y, int set)
{
	set_ground(data, x, y);
	(!check_collect(data)) && (set_exit(data));
	(set && data->map.map[y][x] == '1') && (set_wall(data, x, y));
	if (data->map.map[y][x] == 'E')
	{
		(1) && (data->exit_x = x, data->exit_y = y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.exit[EX],
			x * DM, y * DM);
	}
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.player,
			x * DM, y * DM);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.collect,
			x * DM, y * DM);
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
	data.mlx_win = mlx_new_window(data.mlx, data.map.width * DM,
			data.map.height * DM, TILTEL);
	if (!data.mlx_win)
		return (cleanup(data.map.map, NULL), EXIT_FAILURE);
	mlx_hook(data.mlx_win, 2, 0, mlx_move_player, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_notify, &data);
	if (mlx_init_img(&data))
		return (cleanup(data.map.map, &data), mlx_message_error(3),
			EXIT_FAILURE);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}

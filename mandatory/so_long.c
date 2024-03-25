/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 11:00:42 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_img(t_data *data, int x, int y, int set)
{
	set_ground(data, x, y, set);
	(!check_collect(data)) && (set_exit(data));
	(set && data->map.map[y][x] == '1') && (set_wall(data, x, y));
	if (data->map.map[y][x] == 'E')
	{
		(1) && (data->exit_x = x, data->exit_y = y);
		mlx_image_to_window(data->mlx, data->img.exit[EX],
			x * DM, y * DM);
	}
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_image_to_window(data->mlx, data->img.player,
			x * DM, y * DM);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_image_to_window(data->mlx, data->img.collect,
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
	data.mlx = mlx_init(data.map.width * DM, data.map.height * DM, TILTEL, false);
	if (!data.mlx)
		return (cleanup(data.map.map, NULL), EXIT_FAILURE);
	mlx_key_hook(data.mlx, mlx_move_player, &data);
	if (mlx_init_img(&data))
		return (cleanup(data.map.map, &data), mlx_message_error(3),
			EXIT_FAILURE);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}

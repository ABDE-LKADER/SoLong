/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:39 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_do_effects(t_data *data, void *param)
{
	;
}

void	mlx_put_img(t_data *data, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	set_ground(data, data->img, x, y);
	if (!check_collect(data))
		set_exit(data, data->img, data->exit_x, data->exit_y);
	if (data->map.map[y][x] == '1')
		set_wall(data, data->img, x, y);
	if (data->map.map[y][x] == 'E')
	{
		(1) && (data->exit_x = x, data->exit_y = y);
		mlx_image_to_window(data->mlx, data->img.exit[EX], px, py);
	}
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_image_to_window(data->mlx, data->img.player, px, py);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_image_to_window(data->mlx, data->img.collect, px, py);
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
			mlx_put_img(data, x, y);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.leak = NULL;
	mlx_parce_input(ac, av, &data);
	// is_valid(&data, data.pos_x, data.pos_y);
	data.mlx = mlx_init(data.map.width * DM,
			data.map.height * DM, TILTEL, false);
	if (!data.mlx)
		return (cleanup(&data.leak), EXIT_FAILURE);
	mlx_init_img(&data);
	mlx_key_hook(data.mlx, mlx_move_player, &data);
	mlx_loop_hook(data.mlx, mlx_do_effects, &data);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}

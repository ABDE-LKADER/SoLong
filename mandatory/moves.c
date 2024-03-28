/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/28 06:57:48 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_data *data)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
	data->map.map[--data->pos_y][data->pos_x] = 'P';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
}

static void	move_down(t_data *data)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
	data->map.map[++data->pos_y][data->pos_x] = 'P';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
}

static void	move_right(t_data *data)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
	data->map.map[data->pos_y][++data->pos_x] = 'P';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
}

static void	move_left(t_data *data)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
	data->map.map[data->pos_y][--data->pos_x] = 'P';
	mlx_put_img(data, data->pos_x, data->pos_y, FALSE);
}

void	mlx_move_player(mlx_key_data_t key, void	*param)
{
	t_data	*data;

	data = param;
	data->map.up = data->map.map[data->pos_y - 1][data->pos_x];
	data->map.down = data->map.map[data->pos_y + 1][data->pos_x];
	data->map.left = data->map.map[data->pos_y][data->pos_x - 1];
	data->map.right = data->map.map[data->pos_y][data->pos_x + 1];
	if (key.key == MLX_KEY_ESCAPE)
		exit_game(data);
	if (key.key == MLX_KEY_UP && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.up))
		move_up(data);
	// if (key.key == MLX_KEY_DOWN && key.action != MLX_RELEASE
	// 	&& !ft_strchr("1E", data->map.down))
	// 		move_down(data);
	if (key.key == MLX_KEY_RIGHT && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.right))
		move_right(data);
	if (key.key == MLX_KEY_LEFT && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.left))
		move_left(data);
	if (!map_status(data, key.key))
		exit_game(data);
	while (!ft_strchr("1E", data->map.down))
	{
		ft_printf("DOWN\n");
		move_down(data);
	}
}

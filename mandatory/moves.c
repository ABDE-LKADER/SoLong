/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 11:03:01 by abadouab         ###   ########.fr       */
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

void	mlx_move_player(int key, t_data	*data)
{
	data->map.up = data->map.map[data->pos_y - 1][data->pos_x];
	data->map.down = data->map.map[data->pos_y + 1][data->pos_x];
	data->map.left = data->map.map[data->pos_y][data->pos_x - 1];
	data->map.right = data->map.map[data->pos_y][data->pos_x + 1];
	if (key == ESC)
		exit_game(data);
	else if (key == KUP && !ft_strchr("1E", data->map.up))
		move_up(data);
	else if (key == KDW && !ft_strchr("1E", data->map.down))
		move_down(data);
	else if (key == KRH && !ft_strchr("1E", data->map.right))
		move_right(data);
	else if (key == KLF && !ft_strchr("1E", data->map.left))
		move_left(data);
	else if (!map_status(data, key))
		exit_game(data);
}

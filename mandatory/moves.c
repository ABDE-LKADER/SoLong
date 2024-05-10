/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/10 17:06:25 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_move_up(t_data *data)
{
	int		px;
	int		py;
	int		move;
	int		index;
	int		count;

	(TRUE) && (move = 7, index = A1,
		px = data->pos_x * DM, py = data->pos_y * DM);
	while (move <= 49)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, GROUND, px, py - move);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[index++], px, py - move);
		mlx_do_sync(data->mlx);
		(index == A2) && (index = A1);
		(move == 49) && (--data->pos_y);
		if (data->map.map[data->pos_y][data->pos_x] == 'C')
			data->map.collect--;
		(move == 49) && (data->map.map[data->pos_y][data->pos_x] = 'P');
		(move == 49) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
		if (move == 49)
			mlx_draw_string(data);
		move += 7;
	}
}

static void	mlx_move_down(t_data *data)
{
	int		px;
	int		py;
	int		move;
	int		index;
	int		count;

	(TRUE) && (move = 7, index = A1,
		px = data->pos_x * DM, py = data->pos_y * DM);
	while (move <= 49)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, GROUND, px, py + move);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[index++], px, py + move);
		mlx_do_sync(data->mlx);
		(index == A2) && (index = A1);
		(move == 49) && (++data->pos_y);
		if (data->map.map[data->pos_y][data->pos_x] == 'C')
			data->map.collect--;
		(move == 49) && (data->map.map[data->pos_y][data->pos_x] = 'P');
		(move == 49) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
		if (move == 49)
			mlx_draw_string(data);
		move += 7;
	}
}

static void	mlx_move_left(t_data *data)
{
	int		px;
	int		py;
	int		move;
	int		count;
	int		index;

	(TRUE) && (move = 7, index = R1,
		px = data->pos_x * DM, py = data->pos_y * DM);
	while (index <= R8)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, GROUND, px - move, py);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[index++], px - move, py);
		mlx_do_sync(data->mlx);
		(index == R8) && (--data->pos_x);
		if (data->map.map[data->pos_y][data->pos_x] == 'C')
			data->map.collect--;
		(index == R8) && (data->map.map[data->pos_y][data->pos_x] = 'P');
		(index == R8) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
		if (index == R8)
			mlx_draw_string(data);
		move += 7;
	}
}

static void	mlx_move_right(t_data *data)
{
	int		px;
	int		py;
	int		move;
	int		index;
	int		count;

	(TRUE) && (move = 7, index = R1,
		px = data->pos_x * DM, py = data->pos_y * DM);
	while (index <= R8)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, GROUND, px + move, py);
		mlx_put_image_to_window(data->mlx, data->win,
			data->img[index++], px + move, py);
		mlx_do_sync(data->mlx);
		(index == R8) && (++data->pos_x);
		if (data->map.map[data->pos_y][data->pos_x] == 'C')
			data->map.collect--;
		(index == R8) && (data->map.map[data->pos_y][data->pos_x] = 'P');
		(index == R8) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
		if (index == R8)
			mlx_draw_string(data);
		move += 7;
	}
}

int	mlx_move_player(int key, void *param)
{
	t_map	*map;
	t_data	*data;

	data = param;
	map = &data->map;
	map->up = map->map[data->pos_y - 1][data->pos_x];
	map->down = map->map[data->pos_y + 1][data->pos_x];
	map->left = map->map[data->pos_y][data->pos_x - 1];
	map->right = map->map[data->pos_y][data->pos_x + 1];
	if (key == KEY_ESCAPE)
		exit_game(data, key);
	if (key == KEY_UP && !ft_strchr("1E", data->map.up))
		mlx_move_up(data);
	else if (key == KEY_DOWN && !ft_strchr("1E", data->map.down))
		mlx_move_down(data);
	else if (key == KEY_LEFT && !ft_strchr("1E", data->map.left))
		mlx_move_left(data);
	else if (key == KEY_RIGHT && !ft_strchr("1E", data->map.right))
		mlx_move_right(data);
	if (!map_status(data->map, key))
		exit_game(data, key);
	return (TRUE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 16:45:59 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_set_moves(t_data *data, int x, int y)
{
	int		px;
	int		py;
	int		index;

	(TRUE) && (px = x * DM, py = y * DM);
	mlx_image_to_window(data->mlx, data->img[GR], px, py);
	if (data->map.map[y][x] == 'P')
		mlx_image_to_window(data->mlx, data->img[PL], px, py);
}

void	moving(t_data *data, int direction)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	mlx_set_moves(data, data->pos_x, data->pos_y);
	if (direction == MLX_KEY_UP)
		--data->pos_y;
	if (direction == MLX_KEY_DOWN)
		++data->pos_y;
	if (direction == MLX_KEY_RIGHT)
		++data->pos_x;
	if (direction == MLX_KEY_LEFT)
		--data->pos_x;
	if (data->map.map[data->pos_y][data->pos_x] == 'C')
		data->map.collect--;
	data->map.map[data->pos_y][data->pos_x] = 'P';
	mlx_set_moves(data, data->pos_x, data->pos_y);
	ft_printf(GRN"moves: %d\n"RST, data->moves++);
}

void	mlx_move_player(mlx_key_data_t key, void *param)
{
	t_map	*map;
	t_data	*data;

	data = param;
	map = &data->map;
	map->up = map->map[data->pos_y - 1][data->pos_x];
	map->down = map->map[data->pos_y + 1][data->pos_x];
	map->right = map->map[data->pos_y][data->pos_x + 1];
	map->left = map->map[data->pos_y][data->pos_x - 1];
	if (key.key == MLX_KEY_ESCAPE)
		exit_game(data);
	if (key.key == MLX_KEY_UP && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.up))
		moving(data, MLX_KEY_UP);
	if (key.key == MLX_KEY_DOWN && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.down))
		moving(data, MLX_KEY_DOWN);
	if (key.key == MLX_KEY_RIGHT && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.right))
		moving(data, MLX_KEY_RIGHT);
	if (key.key == MLX_KEY_LEFT && key.action != MLX_RELEASE
		&& !ft_strchr("1E", data->map.left))
		moving(data, MLX_KEY_LEFT);
	if (!map_status(data->map, key))
		exit_game(data);
}

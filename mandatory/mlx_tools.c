/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/22 18:37:43 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checker_set(char **map, char set)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == set)
				return (1);
		}
	}
	return (0);
}

int	map_status(t_map map, int key)
{
	if (checker_set(map.map, 'C'))
		return (1);
	if ((ft_strchr("E", map.up) && key == KEY_UP)
		|| (ft_strchr("E", map.down) && key == KEY_DOWN)
		|| (ft_strchr("E", map.left) && key == KEY_LEFT)
		|| (ft_strchr("E", map.right) && key == KEY_RIGHT))
		return (0);
	return (1);
}

void	flood_fill(char **map, int pos_x, int pos_y)
{
	if (map[pos_y][pos_x] == 'E')
		map[pos_y][pos_x] = '1';
	if (map[pos_y][pos_x] == '1'
		|| map[pos_y][pos_x] == 'X')
		return ;
	map[pos_y][pos_x] = 'X';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}

void	mlx_sync_frame(t_data *data, int key)
{
	data->map.map[data->pos_y][data->pos_x] = '0';
	++data->steps;
	if (key == KEY_UP)
		--data->pos_y;
	if (key == KEY_DOWN)
		++data->pos_y;
	if (key == KEY_LEFT)
		--data->pos_x;
	if (key == KEY_RIGHT)
		++data->pos_x;
	if (data->map.map[data->pos_y][data->pos_x] == 'C')
		data->collect++;
	mlx_draw_string(data);
	if (data->map.map[data->pos_y][data->pos_x] == 'C')
		data->map.collect--;
	data->map.map[data->pos_y][data->pos_x] = 'P';
	ft_printf(GRN"moves: %d\n"RST, data->steps);
}

void	mlx_draw_string(t_data *data)
{
	char			*steps;
	char			*collect;

	steps = ft_itoa(data->steps);
	mlx_put_img(data, WALL2, DM * 2, 0);
	mlx_put_img(data, WALL2, DM * 3, 0);
	if (data->map.width - 1 != 4)
	mlx_put_img(data, WALL2, DM * 4, 0);
	if (data->map.width - 1 != 5)
	mlx_put_img(data, WALL2, DM * 5, 0);
	mlx_string_put(data->mlx, data->win, 152, 5, 0x7A7A7A, "STEPS: ");
	mlx_string_put(data->mlx, data->win, 215, 5, 0x7A7A7A, steps);
	collect = ft_itoa(data->collect);
	mlx_put_img(data, WALL1, 0, 0);
	mlx_put_img(data, WALL2, DM, 0);
	mlx_string_put(data->mlx, data->win, 25, 5, 0x7A7A7A, "COLLECT: ");
	mlx_string_put(data->mlx, data->win, 109, 5, 0x7A7A7A, collect);
	free(collect);
	free(steps);
}

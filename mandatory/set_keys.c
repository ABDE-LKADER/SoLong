/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/09 17:54:44 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *data, int move)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

int	mlx_destroy_notify(t_data *data)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
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

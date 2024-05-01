/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:42:16 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_exit_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	index = E1;

	(TRUE) && (px = data->exit_x * DM, py = data->exit_y * DM);
	if (count % 10 == 0 && index < E8 && !data->map.collect)
	{
		mlx_image_to_window(data->mlx, data->img[GR], px, py);
		mlx_image_to_window(data->mlx, data->img[E8], px, py);
		mlx_image_to_window(data->mlx, data->img[index++], px, py);
	}
}

static void	mlx_idle_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	index = I1;

	(TRUE) && (px = data->pos_x * DM, py = data->pos_y * DM);
	if (count % 25 == 0 && index <= I8)
	{
		mlx_image_to_window(data->mlx, data->img[GR], px, py);
		mlx_image_to_window(data->mlx, data->img[index++], px, py);
		(index == I8) && (index = I1);
	}
}

static void	mlx_fire_effects(t_data *data, t_map *map, int count)
{
	int			x;
	int			y;
	static int	index = F1;

	if (count % 25 == 0 && index <= F8)
	{
		y = -1;
		while (map->map[++y])
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] == 'C')
				{
					mlx_image_to_window(data->mlx, data->img[GR],
						x * DM, y * DM);
					mlx_image_to_window(data->mlx, data->img[index++],
						x * DM, y * DM);
					(index == F8) && (index = F1);
				}
			}
		}
	}
}

void	mlx_do_effects(void *param)
{
	t_map		*map;
	t_data		*data;
	static int	count;

	(TRUE) && (data = param, map = &data->map);
	mlx_idle_effects(data, count);
	mlx_exit_effects(data, count);
	mlx_fire_effects(data, map, count);
	count++;
}

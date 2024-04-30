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

static void	mlx_fire_effects(t_data *data, t_map *map)
{
    ;
}

static void	mlx_exit_effects(t_data *data, t_map *map)
{
	int			px;
	int			py;
	static int	count;
	static int	index = E1;

	if (data->set && !checker_set(data->map.map, 'C'))
		data->set = 0;
	(TRUE) && (px = data->exit_x * DM, py = data->exit_y * DM);
	if (!data->set && count % 10 == 0 && index < E8)
	{
		mlx_image_to_window(data->mlx, data->img[GR], px, py);
		mlx_image_to_window(data->mlx, data->img[E8], px, py);
		mlx_image_to_window(data->mlx, data->img[index++], px, py);
		(index == E7) && (data->set = 1);
	}
	(!data->set) && (count++);
}

void	mlx_do_effects(void *param)
{
	t_map	*map;
	t_data	*data;

	(TRUE) && (data = param, map = &data->map);
    mlx_exit_effects(data, map);
    mlx_fire_effects(data, map);
}

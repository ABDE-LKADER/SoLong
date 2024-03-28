/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/27 15:50:44 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_ground(t_data *data, int x, int y, int set)
{
	mlx_image_to_window(data->mlx, data->img.ground[GR],
		(x * DM), (y * DM));
	// if (set)
	// 	mlx_image_to_window(data->mlx, data->img.ground[GE],
	// 		(x * DM), (y * DM));
    (void)set;
}

int		set_exit(t_data *data)
{
	mlx_image_to_window(data->mlx, data->img.exit[E0],
		data->exit_x * DM, (data->exit_y * DM));
	mlx_image_to_window(data->mlx, data->img.exit[E6],
		data->exit_x * DM, data->exit_y * DM);
	return (1);
}

static void	set_wall_plus(t_data *data, int x, int y)
{
	if (x && !y && data->map.width - 1 != x)
		mlx_image_to_window(data->mlx, data->img.wall[WU],
			x * DM, y * DM);
	else if (y - 1 && (data->map.map[y - 1][x] != '1' || data->map.map[y + 1][x] != '1'))
		mlx_image_to_window(data->mlx, data->img.wall[WA],
			x * DM, y * DM);
	else if (y >= data->map.height / 2)
		mlx_image_to_window(data->mlx, data->img.wall[W2],
			x * DM, y * DM);
	else
	{
		mlx_image_to_window(data->mlx, data->img.wall[W0],
			x * DM, y * DM);
		if (!(y - 1))
			mlx_image_to_window(data->mlx, data->img.wall[WE],
				(x * DM) + 5, y * DM);
	}
}

int		set_wall(t_data *data, int x, int y)
{
	if (!x && !y)
		mlx_image_to_window(data->mlx, data->img.wall[UL],
			x * DM, y * DM);
	else if (!x && y && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, data->img.wall[WL],
			x * DM, y * DM);
	else if (!x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, data->img.wall[DL],
			x * DM, y * DM);
	else if (!y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, data->img.wall[UR],
			x * DM, y * DM);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, data->img.wall[DR],
			x * DM, y * DM);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, data->img.wall[WR],
			x * DM, y * DM);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, data->img.wall[WD],
			x * DM, y * DM);
	else
		set_wall_plus(data, x, y);
	return (1);
}

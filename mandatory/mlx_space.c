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

void	set_ground(t_data *data, int x, int y)
{
	mlx_set_img(data, GROUND, x, y);
}

void	set_exit(t_data *data)
{
	mlx_set_img(data, EXIT6, data->exit_x, data->exit_y);
	mlx_set_img(data, EXIT5, data->exit_x, data->exit_y);
}

static void	set_wall_plus(t_data *data, int x, int y)
{
	if (x && !y && data->map.width - 1 != x)
		mlx_set_img(data, WALL_U, x, y);
	else if (y - 1 && (data->map.map[y - 1][x] != '1'
		|| data->map.map[y + 1][x] != '1'))
		mlx_set_img(data, WALL, x, y);
	else if (y >= data->map.height / 2)
		mlx_set_img(data, WALL2, x, y);
	else
	{
		mlx_set_img(data, WALL0, x, y);
		if (!(y - 1))
			mlx_set_img(data, WALL_E, x + 0.1 , y);
	}
}

void	set_wall(t_data *data, int x, int y)
{
	if (!x && !y)
		mlx_set_img(data, WALL_UL, x, y);
	else if (!x && y && data->map.height - 1 != y)
		mlx_set_img(data, WALL_L, x, y);
	else if (!x && data->map.height - 1 == y)
		mlx_set_img(data, WALL_DL, x, y);
	else if (!y && data->map.width - 1 == x)
		mlx_set_img(data, WALL_UR, x, y);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_set_img(data, WALL_DR, x, y);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_set_img(data, WALL_R, x, y);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_set_img(data, WALL_D, x, y);
	else
		set_wall_plus(data, x, y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/22 10:31:08 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_wall_plus(t_data *data, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (x && !y && data->map.width - 1 != x)
		mlx_put_img(data, WALL2, px, py);
	else if (y - 1 && (data->map.map[y - 1][x] != '1'
		|| data->map.map[y + 1][x] != '1'))
		mlx_put_img(data, SPACE1, px, py);
	else if (y >= data->map.height / 2)
		mlx_put_img(data, SPACE2, px, py);
	else
	{
		mlx_put_img(data, SPACE3, px, py);
		if (!(y - 1))
			mlx_put_img(data, SPACE4, px + 5, py);
	}
}

void	set_wall(t_data *data, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (!x && !y)
		mlx_put_img(data, WALL1, px, py);
	else if (!x && y && data->map.height - 1 != y)
		mlx_put_img(data, WALL4, px, py);
	else if (!x && data->map.height - 1 == y)
		mlx_put_img(data, WALL6, px, py);
	else if (!y && data->map.width - 1 == x)
		mlx_put_img(data, WALL3, px, py);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_put_img(data, WALL8, px, py);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_put_img(data, WALL5, px, py);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_put_img(data, WALL7, px, py);
	else
		set_wall_plus(data, x, y);
}

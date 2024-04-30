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

static void	set_wall_plus(t_data *data, mlx_image_t **img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (x && !y && data->map.width - 1 != x)
		mlx_image_to_window(data->mlx, img[W2], px, py);
	else if (y - 1 && (data->map.map[y - 1][x] != '1'
		|| data->map.map[y + 1][x] != '1'))
		mlx_image_to_window(data->mlx, img[S1], px, py);
	else if (y >= data->map.height / 2)
		mlx_image_to_window(data->mlx, img[S2], px, py);
	else
	{
		mlx_image_to_window(data->mlx, img[S3], px, py);
		if (!(y - 1))
			mlx_image_to_window(data->mlx, img[S4], px + 5, py);
	}
}

void	set_wall(t_data *data, mlx_image_t **img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (!x && !y)
		mlx_image_to_window(data->mlx, img[W1], px, py);
	else if (!x && y && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, img[W4], px, py);
	else if (!x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, img[W6], px, py);
	else if (!y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, img[W3], px, py);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, img[W8], px, py);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, img[W5], px, py);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, img[W7], px, py);
	else
		set_wall_plus(data, img, x, y);
}

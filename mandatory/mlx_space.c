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

void	set_ground(t_data *data, t_img img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	mlx_image_to_window(data->mlx, img.ground[GR], px, py);
}

void	set_exit(t_data *data, t_img img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	mlx_image_to_window(data->mlx, img.ground[GR], px, py);
	mlx_image_to_window(data->mlx, img.exit[E6], px, py);
	mlx_image_to_window(data->mlx, img.exit[E5], px, py);
}

static void	set_wall_plus(t_data *data, t_img img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (x && !y && data->map.width - 1 != x)
		mlx_image_to_window(data->mlx, img.wall[WU], px, py);
	else if (y - 1 && (data->map.map[y - 1][x] != '1'
		|| data->map.map[y + 1][x] != '1'))
		mlx_image_to_window(data->mlx, img.wall[WA], px, py);
	else if (y >= data->map.height / 2)
		mlx_image_to_window(data->mlx, img.wall[W2], px, py);
	else
	{
		mlx_image_to_window(data->mlx, img.wall[W0], px, py);
		if (!(y - 1))
			mlx_image_to_window(data->mlx, img.wall[WE], px + 5, py);
	}
}

void	set_wall(t_data *data, t_img img, int x, int y)
{
	int		px;
	int		py;

	(TRUE) && (px = x * DM, py = y * DM);
	if (!x && !y)
		mlx_image_to_window(data->mlx, img.wall[UL], px, py);
	else if (!x && y && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, img.wall[WL], px, py);
	else if (!x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, img.wall[DL], px, py);
	else if (!y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, img.wall[UR], px, py);
	else if (data->map.height - 1 == y && data->map.width - 1 == x)
		mlx_image_to_window(data->mlx, img.wall[DR], px, py);
	else if (y && data->map.width - 1 == x && data->map.height - 1 != y)
		mlx_image_to_window(data->mlx, img.wall[WR], px, py);
	else if (x && data->map.width - 1 != x && data->map.height - 1 == y)
		mlx_image_to_window(data->mlx, img.wall[WD], px, py);
	else
		set_wall_plus(data, img, x, y);
}

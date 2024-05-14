/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/14 16:45:50 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_put_fire(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = FIRE1);
	(set == 2) && (path = FIRE2);
	(set == 3) && (path = FIRE3);
	(set == 4) && (path = FIRE4);
	(set == 5) && (path = FIRE5);
	(set == 6) && (path = FIRE6);
	(set == 7) && (path = FIRE7);
	(set == 8) && (path = FIRE8);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), mlx_message_error(4, path));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
}

void	mlx_fire_effects(t_data *data, t_map *map, int count)
{
	int			x;
	int			y;
	static int	set;

	if (!(count % 899) && ++set <= 8)
	{
		y = -1;
		while (map->map[++y])
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] == 'C')
				{
					mlx_put_img(data, GROUND, x * DM, y * DM);
					mlx_put_fire(data, set, x * DM, y * DM);
				}
			}
		}
	}
	(set == 8) && (set = 0);
}

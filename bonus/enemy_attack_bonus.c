/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/15 21:58:14 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mlx_put_attack(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = ENEMY1);
	(set == 2) && (path = ENEMY2);
	(set == 3) && (path = ENEMY3);
	(set == 4) && (path = ENEMY4);
	(set == 5) && (path = ENEMY5);
	(set == 6) && (path = ENEMY6);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), mlx_message_error(4, path));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
}

static void	mlx_enemy_handler(t_data *data, int set, int x, int y)
{
	mlx_put_img(data, GROUND, x * DM, y * DM);
	if (x < data->pos_x && !ft_strchr("1CEN", data->map.map[y][x + 1]))
	{
		data->map.map[y][x++] = '0';
		data->map.map[y][x] = 'N';
	}
	else if (x > data->pos_x && !ft_strchr("1CEN", data->map.map[y][x - 1]))
	{
		data->map.map[y][x--] = '0';
		data->map.map[y][x] = 'N';
	}
	else if (y < data->pos_y && !ft_strchr("1CEN", data->map.map[y + 1][x]))
	{
		data->map.map[y++][x] = '0';
		data->map.map[y][x] = 'N';
	}
	else if (y > data->pos_y && !ft_strchr("1CEN", data->map.map[y - 1][x]))
	{
		data->map.map[y--][x] = '0';
		data->map.map[y][x] = 'N';
	}
	if (x == data->pos_x && y == data->pos_y)
		exit_game(data, FALSE);
	mlx_put_img(data, GROUND, x * DM, y * DM);
	mlx_put_attack(data, set, x * DM, y * DM);
}

void	mlx_enemy_attack(t_data *data, t_map *map, int count)
{
	int	x;
	static int	y  = -1;
	static int	set;

	if (!(count % 999) && ++set <= 6)
	{
		if (y == map->height)
			y = -1;
		while (map->map[++y])
		{
			x = -1;
			while (map->map[y][++x])
			{
				if (map->map[y][x] == 'N')
				{
					mlx_enemy_handler(data, set, x, y);
					return ;
				}
			}
		}
	}
	(set == 6) && (set = 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/22 12:57:16 by abadouab         ###   ########.fr       */
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
	if (x > data->pos_x && !ft_strchr("1CEN", data->map.map[y][x - 1]))
	{
		data->map.map[y][x--] = '0';
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

static void	mlx_enemy_handler_plus(t_data *data, int set, int x, int y)
{
	mlx_put_img(data, GROUND, x * DM, y * DM);
	if (x < data->pos_x && !ft_strchr("1CEN", data->map.map[y][x + 1]))
	{
		data->map.map[y][x++] = '0';
		data->map.map[y][x] = 'N';
	}
	else if (y < data->pos_y && !ft_strchr("1CEN", data->map.map[y + 1][x]))
	{
		data->map.map[y++][x] = '0';
		data->map.map[y][x] = 'N';
	}
	if (x == data->pos_x && y == data->pos_y)
		exit_game(data, FALSE);
	mlx_put_img(data, GROUND, x * DM, y * DM);
	mlx_put_attack(data, set, x * DM, y * DM);
}

static void	mlx_enemy_attack_plus(t_data *data, t_map *map, int set)
{
	static int	y;
	static int	x;
	static int	one;

	(!one) && (x = map->width - 1, y = map->height - 1, one = 1);
	(y == -1) && (y = map->height - 1);
	while (y >= 0)
	{
		ft_printf("Y -----_> %d\n", y);
		(x == -1) && (x = map->width - 1);
		while (x >= 0)
		{
			ft_printf("X -----_> %d\n", x);
			if (map->map[y][x] == 'N')
			{
				mlx_enemy_handler_plus(data, set, x, y);
				return ;
			}
			x--;
		}
		(x == -1) && (y--);
	}
}

void	mlx_enemy_attack(t_data *data, t_map *map, int count)
{
	static int	y;
	static int	set;
	static int	x = -1;

	if (++set <= 6 && !(count % 999))
	{
		if (x > data->pos_x || y > data->pos_y)
		{
			(y == map->height) && (y = 0);
			while (map->map[y])
			{
				if (x == map->width)
					x = -1;
				while (map->map[y][++x])
				{
					if (map->map[y][x] == 'N')
					{
						mlx_enemy_handler(data, set, x, y);
						return ;
					}
				}
				(x == map->width) && (y++);
			}
		}
	}
	else if (x < data->pos_x || y < data->pos_y)
		mlx_enemy_attack_plus(data, map, set);
	(set == 6) && (set = 0);
}

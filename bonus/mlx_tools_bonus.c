/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/12 15:05:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_put_img(t_data *data, char *path, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
}

void	flood_fill(char **map, int pos_x, int pos_y)
{
	if (map[pos_y][pos_x] == 'E')
		map[pos_y][pos_x] = '1';
	if (map[pos_y][pos_x] == '1'
		|| map[pos_y][pos_x] == 'X')
		return ;
	map[pos_y][pos_x] = 'X';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}

void	mlx_sync_frame(t_data *data, int key)
{
	if (key == KEY_UP)
		--data->pos_y;
	if (key == KEY_DOWN)
		++data->pos_y;
	if (key == KEY_LEFT)
		--data->pos_x;
	if (key == KEY_RIGHT)
		++data->pos_x;
	if (data->map.map[data->pos_y][data->pos_x] == 'C')
		data->map.collect--;
	data->map.map[data->pos_y][data->pos_x] = 'P';
	ft_printf(GRN"moves: %d\n"RST, data->steps++);
	mlx_draw_string(data);
}

int	checker_set(char **map, char set)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == set)
				return (1);
		}
	}
	return (0);
}

int	map_status(t_map map, int key)
{
	if (checker_set(map.map, 'C'))
		return (1);
	if ((ft_strchr("E", map.up) && key == KEY_UP)
		|| (ft_strchr("E", map.down) && key == KEY_DOWN)
		|| (ft_strchr("E", map.left) && key == KEY_LEFT)
		|| (ft_strchr("E", map.right) && key == KEY_RIGHT))
		return (0);
	return (1);
}

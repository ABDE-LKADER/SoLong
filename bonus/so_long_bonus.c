/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/12 15:17:06 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*mlx_enemy_attack(t_data *data, t_map *map, int count)
{
	
}

static int	mlx_do_effects(void *param)
{
	t_map		*map;
	t_data		*data;
	static int	count;

	(TRUE) && (data = param, map = &data->map);
	mlx_idle_effects(data, count);
	mlx_exit_effects(data, count);
	mlx_fire_effects(data, map, count);
	mlx_enemy_attack(data, map, count);
	// if (!ft_strchr("1E", map->map[data->pos_y + 1][data->pos_x])
	// 	&& count % 100 == 0)
	// 	mlx_move_down(data);
	return (count++);
}

static int	mlx_move_player(int key, void *param)
{
	t_map	*map;
	t_data	*data;

	data = param;
	map = &data->map;
	map->up = map->map[data->pos_y - 1][data->pos_x];
	map->down = map->map[data->pos_y + 1][data->pos_x];
	map->left = map->map[data->pos_y][data->pos_x - 1];
	map->right = map->map[data->pos_y][data->pos_x + 1];
	if (key == KEY_ESCAPE)
		exit_game(data);
	if (key == KEY_UP && !ft_strchr("1E", data->map.up))
		mlx_move_up(data, key);
	else if (key == KEY_DOWN && !ft_strchr("1E", data->map.down))
		mlx_move_down(data, key);
	else if (key == KEY_LEFT && !ft_strchr("1E", data->map.left))
		mlx_move_left(data, key);
	else if (key == KEY_RIGHT && !ft_strchr("1E", data->map.right))
		mlx_move_right(data, key);
	if (!map_status(data->map, key))
		exit_game(data);
	return (TRUE);
}

static void	mlx_game_render(t_data *data)
{
	int		y;
	int		x;
	int		px;
	int		py;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			(TRUE) && (px = x * DM, py = y * DM);
			mlx_put_img(data, GROUND, px, py);
			if (data->map.map[y][x] == '1')
				set_wall(data, x, y);
			else if (data->map.map[y][x] == 'E')
				mlx_put_img(data, EXIT1, px, py);
			else if (data->map.map[y][x] == 'P')
				mlx_put_img(data, IDLE1, px, py);
			else if (data->map.map[y][x] == 'N')
				mlx_put_img(data, ENEMY1, px, py);
			else if (data->map.map[y][x] == 'C')
				mlx_put_img(data, FIRE1, px, py);
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	mlx_parce_input(ac, av, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (cleanup(&data.leak), EXIT_FAILURE);
	data.win = mlx_new_window(data.mlx, data.map.width * DM,
			data.map.height * DM, TILTEL);
	if (!data.win)
		return (cleanup(&data.leak), free(data.mlx), EXIT_FAILURE);
	mlx_game_render(&data);
	mlx_draw_string(&data);
	mlx_hook(data.win, 17, 0L, mlx_destroy_notify, &data);
	mlx_hook(data.win, 02, 0L, mlx_move_player, &data);
	mlx_loop_hook(data.mlx, mlx_do_effects, &data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}

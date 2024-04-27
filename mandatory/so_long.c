/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:29:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_set_img(t_data *data, char *path, int x, int y)
{
	mlx_image_t		*img;
	mlx_texture_t	*txr;

	txr = mlx_load_png(path);
	if (!txr)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	img = mlx_texture_to_image(data->mlx, txr);
	mlx_image_to_window(data->mlx, img, x * DM, y * DM);
	mlx_delete_texture(txr);
}

void	mlx_put_img(t_data *data, int x, int y)
{
	set_ground(data, x, y);
	if (!check_collect(data))
		set_exit(data);
	if (data->map.map[y][x] == '1')
		set_wall(data, x, y);
	if (data->map.map[y][x] == 'E')
	{
		(1) && (data->exit_x = x, data->exit_y = y);
		mlx_set_img(data, EXIT, x, y);
	}
	else if (data->map.map[y][x] == 'P')
	{
		(1) && (data->pos_x = x, data->pos_y = y);
		mlx_set_img(data, PLAYER, x, y);
	}
	else if (data->map.map[y][x] == 'C')
		mlx_set_img(data, COLLECT, x, y);
}

static void	mlx_game_render(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
			mlx_put_img(data, x, y);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	(mlx_parce_input(ac, av, &data), is_valid(&data));
	data.mlx = mlx_init(data.map.width * DM,
			data.map.height * DM, TILTEL, false);
	if (!data.mlx)
		return (cleanup(&data.leak), EXIT_FAILURE);
	mlx_key_hook(data.mlx, mlx_move_player, &data);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/10 10:12:42 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_put_img(t_data *data, char *path, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
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
				set_wall(data, data->img, x, y);
			else if (data->map.map[y][x] == 'E')
				mlx_put_img(data, EXIT1, px, py);
			else if (data->map.map[y][x] == 'P')
				mlx_put_img(data, IDLE1, px, py);
			else if (data->map.map[y][x] == 'C')
				mlx_put_img(data, FIRE1, px, py);
		}
	}
	mlx_draw_string(data);
}

void lk(void){system("leaks so_long");}
int	main(int ac, char **av)
{
	t_data	data;

	atexit(lk);
	mlx_parce_input(ac, av, &data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (cleanup(&data.leak), EXIT_FAILURE);
	data.win = mlx_new_window(data.mlx, data.map.width * DM,
			data.map.height * DM, TILTEL);
	if (!data.win)
		return (cleanup(&data.leak), EXIT_FAILURE);
	mlx_init_img(&data);
	mlx_hook(data.win, 17, 0L, mlx_destroy_notify, &data);
	mlx_hook(data.win, 02, 0L, mlx_move_player, &data);
	mlx_loop_hook(data.mlx, mlx_do_effects, &data);
	mlx_game_render(&data);
	mlx_loop(data.mlx);
	return (EXIT_SUCCESS);
}

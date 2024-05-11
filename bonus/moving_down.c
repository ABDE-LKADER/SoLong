/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 20:26:09 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

////////////////////////// GRAVITY ////////////////////////////
// void	mlx_move_down(t_data *data)
// {
// 	int		px;
// 	int		py;
// 	int		move;
// 	int		index;
// 	int		count;

// 	(TRUE) && (move = 7, index = A1,
// 		px = data->pos_x * DM, py = data->pos_y * DM);
// 	while (move <= 49)
// 	{
// 		mlx_put_img(data, GROUND, px, py);
// 		mlx_put_img(data, GROUND, px, py + move);
// 		mlx_put_image_to_window(data->mlx, data->win,
// 			data->img[index++], px, py + move);
// 		mlx_do_sync(data->mlx);
// 		(index == A2) && (index = A1);
// 		(move == 49) && (++data->pos_y);
// 		if (data->map.map[data->pos_y][data->pos_x] == 'C')
// 			data->map.collect--;
// 		(move == 49) && (data->map.map[data->pos_y][data->pos_x] = 'P');
// 		(move == 49) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
// 		if (move == 49)
// 			mlx_draw_string(data);
// 		move += 7;
// 	}
// }

static void	moving_down(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = FALL1);
	(set == 2) && (path = FALL2);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_do_sync(data->mlx);
	mlx_destroy_image(data->mlx, img);
}

void	mlx_move_down(t_data *data, int key)
{
	int		px;
	int		py;
	int		move;
	int		set;

	(TRUE) && (move = 7, set = 0);
	(TRUE) && (px = data->pos_x * DM, py = data->pos_y * DM);
	while (move <= 49)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_img(data, GROUND, px, py + move);
		moving_down(data, ++set, px, py + move);
		(set == 2) && (set = 0);
		mlx_do_sync(data->mlx);
		if (move == 49)
			mlx_sync_frame(data, key);
		move += 7;
	}
}

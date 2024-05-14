/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_right_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/14 22:41:19 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	moving_right(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = RIGHT1);
	(set == 2) && (path = RIGHT2);
	(set == 3) && (path = RIGHT3);
	(set == 4) && (path = RIGHT4);
	(set == 5) && (path = RIGHT5);
	(set == 6) && (path = RIGHT6);
	(set == 7) && (path = RIGHT7);
	(set == 8) && (path = RIGHT8);
	if (data->map.map[data->pos_y][data->pos_x + 1] == 'C')
		mlx_put_img(data, GROUND, (data->pos_x + 1) * DM, y);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), mlx_message_error(4, path));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_do_sync(data->mlx);
	mlx_destroy_image(data->mlx, img);
}

void	mlx_move_right(t_data *data, int key)
{
	int		px;
	int		py;
	int		move;
	int		set;

	(TRUE) && (set = 0, move = 7);
	(TRUE) && (px = data->pos_x * DM, py = data->pos_y * DM);
	while (move <= 49)
	{
		mlx_put_img(data, GROUND, px, py);
		moving_right(data, ++set, px + move, py);
		mlx_do_sync(data->mlx);
		if (move == 49)
			mlx_sync_frame(data, key);
		move += 7;
	}
}

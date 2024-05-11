/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 15:03:53 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	moving_up(t_data *data, int set, int x, int y)
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

void	mlx_move_up(t_data *data, int key)
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
		mlx_put_img(data, GROUND, px, py - move);
		moving_up(data, ++set, px, py - move);
		mlx_do_sync(data->mlx);
		(set == 2) && (set = 0);
		if (move == 49)
			mlx_sync_frame(data, key);
		move += 7;
	}
}

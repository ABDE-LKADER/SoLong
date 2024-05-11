/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idle_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:54:07 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 11:50:35 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_put_idle(t_data *data, int set, int x, int y)
{
	void	*img;
	char	*path;

	(set == 1) && (path = IDLE1);
	(set == 2) && (path = IDLE2);
	(set == 3) && (path = IDLE3);
	(set == 4) && (path = IDLE4);
	(set == 5) && (path = IDLE5);
	(set == 6) && (path = IDLE6);
	(set == 7) && (path = IDLE7);
	(set == 8) && (path = IDLE8);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	mlx_put_image_to_window(data->mlx, data->win, img, x, y);
	mlx_destroy_image(data->mlx, img);
}

void	mlx_idle_effects(t_data *data, int count)
{
	int			px;
	int			py;
	static int	set;

	(TRUE) && (px = data->pos_x * DM, py = data->pos_y * DM);
	if (count % 299 == 0 && ++set <= 8)
	{
		mlx_put_img(data, GROUND, px, py);
		mlx_put_idle(data, set, px, py);
		(set == 8) && (set = 0);
	}
}

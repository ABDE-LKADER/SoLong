/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:02:13 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/09 14:24:02 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*mlx_init_new_img(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	return (img);
}

static void	mlx_init_plus(t_data *data, void **img)
{
	img[E1] = mlx_init_new_img(data, EXIT1);
	img[E2] = mlx_init_new_img(data, EXIT2);
	img[E3] = mlx_init_new_img(data, EXIT3);
	img[E4] = mlx_init_new_img(data, EXIT4);
	img[E5] = mlx_init_new_img(data, EXIT5);
	img[E6] = mlx_init_new_img(data, EXIT6);
	img[E7] = mlx_init_new_img(data, EXIT7);
	img[E8] = mlx_init_new_img(data, EXIT8);
	img[F1] = mlx_init_new_img(data, FIRE1);
	img[F2] = mlx_init_new_img(data, FIRE2);
	img[F3] = mlx_init_new_img(data, FIRE3);
	img[F4] = mlx_init_new_img(data, FIRE4);
	img[F5] = mlx_init_new_img(data, FIRE5);
	img[F6] = mlx_init_new_img(data, FIRE6);
	img[F7] = mlx_init_new_img(data, FIRE7);
	img[F8] = mlx_init_new_img(data, FIRE8);
}

void	mlx_init_img(t_data	*data)
{
	mlx_init_plus(data, data->img);
	data->img[A1] = mlx_init_new_img(data, FALL1);
	data->img[A2] = mlx_init_new_img(data, FALL2);
	data->img[I1] = mlx_init_new_img(data, IDLE1);
	data->img[I2] = mlx_init_new_img(data, IDLE2);
	data->img[I3] = mlx_init_new_img(data, IDLE3);
	data->img[I4] = mlx_init_new_img(data, IDLE4);
	data->img[I5] = mlx_init_new_img(data, IDLE5);
	data->img[I6] = mlx_init_new_img(data, IDLE6);
	data->img[I7] = mlx_init_new_img(data, IDLE7);
	data->img[I8] = mlx_init_new_img(data, IDLE8);
	data->img[R1] = mlx_init_new_img(data, RIGHT1);
	data->img[R2] = mlx_init_new_img(data, RIGHT2);
	data->img[R3] = mlx_init_new_img(data, RIGHT3);
	data->img[R4] = mlx_init_new_img(data, RIGHT4);
	data->img[R5] = mlx_init_new_img(data, RIGHT5);
	data->img[R6] = mlx_init_new_img(data, RIGHT6);
	data->img[R7] = mlx_init_new_img(data, RIGHT7);
	data->img[R8] = mlx_init_new_img(data, RIGHT8);
}

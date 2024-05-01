/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:02:13 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/27 16:49:26 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*mlx_init_new_img(t_data *data, char *path)
{
	mlx_image_t		*img;
	mlx_texture_t	*txr;

	txr = mlx_load_png(path);
	if (!txr)
		(cleaning(&data->leak, data), exit(EXIT_FAILURE));
	img = mlx_texture_to_image(data->mlx, txr);
	if (!img)
		(mlx_delete_texture(txr), cleaning(&data->leak, data),
			exit(EXIT_FAILURE));
	mlx_delete_texture(txr);
	return (img);
}

static void	mlx_init_plus(t_data *data, mlx_image_t **img)
{
	img[GR] = mlx_init_new_img(data, GROUND);
	img[PL] = mlx_init_new_img(data, PLAYER);
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
	data->img[W1] = mlx_init_new_img(data, WALL1);
	data->img[W2] = mlx_init_new_img(data, WALL2);
	data->img[W3] = mlx_init_new_img(data, WALL3);
	data->img[W4] = mlx_init_new_img(data, WALL4);
	data->img[W5] = mlx_init_new_img(data, WALL5);
	data->img[W6] = mlx_init_new_img(data, WALL6);
	data->img[W7] = mlx_init_new_img(data, WALL7);
}

void	mlx_init_img(t_data	*data)
{
	mlx_init_plus(data, data->img);
	data->img[W8] = mlx_init_new_img(data, WALL8);
	data->img[S1] = mlx_init_new_img(data, SPACE1);
	data->img[S2] = mlx_init_new_img(data, SPACE2);
	data->img[S3] = mlx_init_new_img(data, SPACE3);
	data->img[S4] = mlx_init_new_img(data, SPACE4);
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

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
	if (!txr)
		(mlx_delete_texture(txr), cleaning(&data->leak, data),
			exit(EXIT_FAILURE));
	mlx_delete_texture(txr);
	return (img);
}

static void	mlx_init_exit(t_data *data, t_img *img)
{
	img->exit[EX] = mlx_init_new_img(data, EXIT);
	img->exit[E0] = mlx_init_new_img(data, EXIT0);
	img->exit[E1] = mlx_init_new_img(data, EXIT1);
	img->exit[E2] = mlx_init_new_img(data, EXIT2);
	img->exit[E3] = mlx_init_new_img(data, EXIT3);
	img->exit[E4] = mlx_init_new_img(data, EXIT4);
	img->exit[E5] = mlx_init_new_img(data, EXIT5);
	img->exit[E6] = mlx_init_new_img(data, EXIT6);
}

static void	mlx_init_wall(t_data *data, t_img *img)
{
	img->wall[WA] = mlx_init_new_img(data, WALL);
	img->wall[W0] = mlx_init_new_img(data, WALL0);
	img->wall[W2] = mlx_init_new_img(data, WALL2);
	img->wall[WE] = mlx_init_new_img(data, WALL_E);
	img->wall[WL] = mlx_init_new_img(data, WALL_L);
	img->wall[WR] = mlx_init_new_img(data, WALL_R);
	img->wall[WU] = mlx_init_new_img(data, WALL_U);
	img->wall[WD] = mlx_init_new_img(data, WALL_D);
	img->wall[DL] = mlx_init_new_img(data, WALL_DL);
	img->wall[UL] = mlx_init_new_img(data, WALL_UL);
	img->wall[DR] = mlx_init_new_img(data, WALL_DR);
	img->wall[UR] = mlx_init_new_img(data, WALL_UR);
}

void	mlx_init_img(t_data	*data)
{
	t_img	*img;

	img = &data->img;
	mlx_init_wall(data, img);
	mlx_init_exit(data, img);
	img->player = mlx_init_new_img(data, PLAYER);
	img->collect = mlx_init_new_img(data, COLLECT);
	img->ground[GR] = mlx_init_new_img(data, GROUND);
	img->ground[G2] = mlx_init_new_img(data, GROUND2);
	img->ground[G3] = mlx_init_new_img(data, GROUND3);
}

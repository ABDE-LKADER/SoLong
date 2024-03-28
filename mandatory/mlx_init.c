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

static int	mlx_init_wall(mlx_t *mlx, t_txr *txr, t_img *img, int check)
{
	(!(img->wall[WA] = mlx_texture_to_image(mlx, txr->wall[WA]))) && (check = 0);
	(!(img->wall[W0] = mlx_texture_to_image(mlx, txr->wall[W0]))) && (check = 0);
	(!(img->wall[W2] = mlx_texture_to_image(mlx, txr->wall[W2]))) && (check = 0);
	(!(img->wall[WE] = mlx_texture_to_image(mlx, txr->wall[WE]))) && (check = 0);
	(!(img->wall[WL] = mlx_texture_to_image(mlx, txr->wall[WL]))) && (check = 0);
	(!(img->wall[WR] = mlx_texture_to_image(mlx, txr->wall[WR]))) && (check = 0);
	(!(img->wall[WU] = mlx_texture_to_image(mlx, txr->wall[WU]))) && (check = 0);
	(!(img->wall[WD] = mlx_texture_to_image(mlx, txr->wall[WD]))) && (check = 0);
	(!(img->wall[DL] = mlx_texture_to_image(mlx, txr->wall[DL]))) && (check = 0);
	(!(img->wall[UL] = mlx_texture_to_image(mlx, txr->wall[UL]))) && (check = 0);
	(!(img->wall[DR] = mlx_texture_to_image(mlx, txr->wall[DR]))) && (check = 0);
	(!(img->wall[UR] = mlx_texture_to_image(mlx, txr->wall[UR]))) && (check = 0);
	return (check);
}

static int	mlx_init_exit(mlx_t *mlx, t_txr *txr, t_img *img, int check)
{
	(!(img->exit[EX] = mlx_texture_to_image(mlx, txr->exit[EX]))) && (check = 0);
	(!(img->exit[E0] = mlx_texture_to_image(mlx, txr->exit[E0]))) && (check = 0);
	(!(img->exit[E1] = mlx_texture_to_image(mlx, txr->exit[E1]))) && (check = 0);
	(!(img->exit[E2] = mlx_texture_to_image(mlx, txr->exit[E2]))) && (check = 0);
	(!(img->exit[E3] = mlx_texture_to_image(mlx, txr->exit[E3]))) && (check = 0);
	(!(img->exit[E4] = mlx_texture_to_image(mlx, txr->exit[E4]))) && (check = 0);
	(!(img->exit[E5] = mlx_texture_to_image(mlx, txr->exit[E5]))) && (check = 0);
	(!(img->exit[E6] = mlx_texture_to_image(mlx, txr->exit[E6]))) && (check = 0);
	return (check);
}

int	mlx_init_img(t_data	*data)
{
	int     check;
	mlx_t	*mlx;
	t_txr	*txr;
	t_img	*img;

	(1) && (check = 1, mlx = data->mlx, txr = &data->txr, img = &data->img);
	check = mlx_load_img(txr);
	check = mlx_init_wall(mlx, txr, img, check);
	check = mlx_init_exit(mlx, txr, img, check);
	(!(img->player = mlx_texture_to_image(mlx, txr->player))) && (check = 0);
	(!(img->collect = mlx_texture_to_image(mlx, txr->collect))) && (check = 0);
	(!(img->ground[GR] = mlx_texture_to_image(mlx, txr->ground[GR]))) && (check = 0);
	return (check);
}

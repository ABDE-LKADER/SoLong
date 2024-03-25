/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:43:16 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 10:34:47 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mlx_load_wall(t_data *data, t_img *img, int check)
{
	(!(img->wall[WA] = mlx_load_png(WALL))) && (check = 0);
	(!(img->wall[W0] = mlx_load_png(WALL0))) && (check = 0);
	(!(img->wall[W2] = mlx_load_png(WALL2))) && (check = 0);
	(!(img->wall[WE] = mlx_load_png(WALL_E))) && (check = 0);
	(!(img->wall[WL] = mlx_load_png(WALL_L))) && (check = 0);
	(!(img->wall[WR] = mlx_load_png(WALL_R))) && (check = 0);
	(!(img->wall[WU] = mlx_load_png(WALL_U))) && (check = 0);
	(!(img->wall[WD] = mlx_load_png(WALL_D))) && (check = 0);
	(!(img->wall[DL] = mlx_load_png(WALL_DL))) && (check = 0);
	(!(img->wall[UL] = mlx_load_png(WALL_UL))) && (check = 0);
	(!(img->wall[DR] = mlx_load_png(WALL_DR))) && (check = 0);
	(!(img->wall[UR] = mlx_load_png(WALL_UR))) && (check = 0);
	return (check);
}

static int	mlx_load_exit(t_data *data, t_img *img, int check)
{
	(!(img->exit[EX] = mlx_load_png(EXIT))) && (check = 0);
	(!(img->exit[E0] = mlx_load_png(EXIT0))) && (check = 0);
	(!(img->exit[E1] = mlx_load_png(EXIT1))) && (check = 0);
	(!(img->exit[E2] = mlx_load_png(EXIT2))) && (check = 0);
	(!(img->exit[E3] = mlx_load_png(EXIT3))) && (check = 0);
	(!(img->exit[E4] = mlx_load_png(EXIT4))) && (check = 0);
	(!(img->exit[E5] = mlx_load_png(EXIT5))) && (check = 0);
	(!(img->exit[E6] = mlx_load_png(EXIT6))) && (check = 0);
	return (check);
}

int	mlx_load_img(t_data *data)
{
	int     check;
	t_img	*img;

	check = 1;
	img = &data->img;
	check = mlx_init_wall(data, img, check);
	check = mlx_init_exit(data, img, check);
	(!(img->player = mlx_load_png(PLAYER))) && (check = 0);
	(!(img->collect = mlx_load_png(COLLECT))) && (check = 0);
	(!(img->ground[GR] = mlx_load_png(GROUND))) && (check = 0);
	(!(img->ground[GE] = mlx_load_png(GROUND_E))) && (check = 0);
	if (!check)
		return (1);
	return (0);
}

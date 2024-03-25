/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:02:13 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/25 10:59:12 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mlx_init_wall(t_data *data, t_img *img, int check)
{
	(!(img->wall[WA] = mlx_texture_to_image(data->mlx, WALL))) && (check = 0);
	(!(img->wall[W0] = mlx_texture_to_image(data->mlx, WALL0))) && (check = 0);
	(!(img->wall[W2] = mlx_texture_to_image(data->mlx, WALL2))) && (check = 0);
	(!(img->wall[WE] = mlx_texture_to_image(data->mlx, WALL_E))) && (check = 0);
	(!(img->wall[WL] = mlx_texture_to_image(data->mlx, WALL_L))) && (check = 0);
	(!(img->wall[WR] = mlx_texture_to_image(data->mlx, WALL_R))) && (check = 0);
	(!(img->wall[WU] = mlx_texture_to_image(data->mlx, WALL_U))) && (check = 0);
	(!(img->wall[WD] = mlx_texture_to_image(data->mlx, WALL_D))) && (check = 0);
	(!(img->wall[DL] = mlx_texture_to_image(data->mlx, WALL_DL))) && (check = 0);
	(!(img->wall[UL] = mlx_texture_to_image(data->mlx, WALL_UL))) && (check = 0);
	(!(img->wall[DR] = mlx_texture_to_image(data->mlx, WALL_DR))) && (check = 0);
	(!(img->wall[UR] = mlx_texture_to_image(data->mlx, WALL_UR))) && (check = 0);
	return (check);
}

static int	mlx_init_exit(t_data *data, t_img *img, int check)
{
	(!(img->exit[EX] = mlx_texture_to_image(data->mlx, EXIT))) && (check = 0);
	(!(img->exit[E0] = mlx_texture_to_image(data->mlx, EXIT0))) && (check = 0);
	(!(img->exit[E1] = mlx_texture_to_image(data->mlx, EXIT1))) && (check = 0);
	(!(img->exit[E2] = mlx_texture_to_image(data->mlx, EXIT2))) && (check = 0);
	(!(img->exit[E3] = mlx_texture_to_image(data->mlx, EXIT3))) && (check = 0);
	(!(img->exit[E4] = mlx_texture_to_image(data->mlx, EXIT4))) && (check = 0);
	(!(img->exit[E5] = mlx_texture_to_image(data->mlx, EXIT5))) && (check = 0);
	(!(img->exit[E6] = mlx_texture_to_image(data->mlx, EXIT6))) && (check = 0);
	return (check);
}

int	mlx_init_img(t_data	*data)
{
	int     check;
	t_img	*img;

	check = 1;
	img = &data->img;
	check = mlx_init_wall(data, img, check);
	check = mlx_init_exit(data, img, check);
	(!(img->ground[GR] = mlx_texture_to_image(data->mlx, GROUND))) && (check = 0);
	(!(img->ground[GE] = mlx_texture_to_image(data->mlx, GROUND_E))) && (check = 0);
	(!(img->player = mlx_texture_to_image(data->mlx, PLAYER))) && (check = 0);
	(!(img->collect = mlx_texture_to_image(data->mlx, COLLECT))) && (check = 0);
	if (!check)
		return (1);
	return (0);
}

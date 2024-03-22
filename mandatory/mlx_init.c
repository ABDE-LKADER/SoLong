/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 08:02:13 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/22 17:59:40 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mlx_init_wall(t_data *data, t_img *img, int check)
{
	(!(img->wall[WA] = mlx_xpm_file_to_image(data->mlx, WALL,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[W0] = mlx_xpm_file_to_image(data->mlx, WALL0,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[W2] = mlx_xpm_file_to_image(data->mlx, WALL2,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[WE] = mlx_xpm_file_to_image(data->mlx, WALL_E,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[WL] = mlx_xpm_file_to_image(data->mlx, WALL_L,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[WR] = mlx_xpm_file_to_image(data->mlx, WALL_R,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[WU] = mlx_xpm_file_to_image(data->mlx, WALL_U,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[WD] = mlx_xpm_file_to_image(data->mlx, WALL_D,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[DL] = mlx_xpm_file_to_image(data->mlx, WALL_DL,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[UL] = mlx_xpm_file_to_image(data->mlx, WALL_UL,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[DR] = mlx_xpm_file_to_image(data->mlx, WALL_DR,
			&img->width, &img->height))) && (check = 0);
	(!(img->wall[UR] = mlx_xpm_file_to_image(data->mlx, WALL_UR,
			&img->width, &img->height))) && (check = 0);
	return (check);
}

static int	mlx_init_exit(t_data *data, t_img *img, int check)
{
	(!(img->exit[EX] = mlx_xpm_file_to_image(data->mlx, EXIT,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E0] = mlx_xpm_file_to_image(data->mlx, EXIT0,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E1] = mlx_xpm_file_to_image(data->mlx, EXIT1,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E2] = mlx_xpm_file_to_image(data->mlx, EXIT2,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E3] = mlx_xpm_file_to_image(data->mlx, EXIT3,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E4] = mlx_xpm_file_to_image(data->mlx, EXIT4,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E5] = mlx_xpm_file_to_image(data->mlx, EXIT5,
			&img->width, &img->height))) && (check = 0);
	(!(img->exit[E6] = mlx_xpm_file_to_image(data->mlx, EXIT6,
			&img->width, &img->height))) && (check = 0);
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
	(!(img->ground = mlx_xpm_file_to_image(data->mlx, GROUND,
			&img->width, &img->height))) && (check = 0);
	(!(img->player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&img->width, &img->height))) && (check = 0);
	(!(img->collect = mlx_xpm_file_to_image(data->mlx, COLLECT,
			&img->width, &img->height))) && (check = 0);
	if (!check)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 07:43:16 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/27 16:49:06 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	mlx_load_wall(t_txr *txr, int check)
{
	(!(txr->wall[WA] = mlx_load_png(WALL))) && (check = 0);
	(!(txr->wall[W0] = mlx_load_png(WALL0))) && (check = 0);
	(!(txr->wall[W2] = mlx_load_png(WALL2))) && (check = 0);
	(!(txr->wall[WE] = mlx_load_png(WALL_E))) && (check = 0);
	(!(txr->wall[WL] = mlx_load_png(WALL_L))) && (check = 0);
	(!(txr->wall[WR] = mlx_load_png(WALL_R))) && (check = 0);
	(!(txr->wall[WU] = mlx_load_png(WALL_U))) && (check = 0);
	(!(txr->wall[WD] = mlx_load_png(WALL_D))) && (check = 0);
	(!(txr->wall[DL] = mlx_load_png(WALL_DL))) && (check = 0);
	(!(txr->wall[UL] = mlx_load_png(WALL_UL))) && (check = 0);
	(!(txr->wall[DR] = mlx_load_png(WALL_DR))) && (check = 0);
	(!(txr->wall[UR] = mlx_load_png(WALL_UR))) && (check = 0);
	return (check);
}

static int	mlx_load_exit(t_txr *txr, int check)
{
	(!(txr->exit[EX] = mlx_load_png(EXIT))) && (check = 0);
	(!(txr->exit[E0] = mlx_load_png(EXIT0))) && (check = 0);
	(!(txr->exit[E1] = mlx_load_png(EXIT1))) && (check = 0);
	(!(txr->exit[E2] = mlx_load_png(EXIT2))) && (check = 0);
	(!(txr->exit[E3] = mlx_load_png(EXIT3))) && (check = 0);
	(!(txr->exit[E4] = mlx_load_png(EXIT4))) && (check = 0);
	(!(txr->exit[E5] = mlx_load_png(EXIT5))) && (check = 0);
	(!(txr->exit[E6] = mlx_load_png(EXIT6))) && (check = 0);
	return (check);
}

int	mlx_load_img(t_txr *txr)
{
	int     check;

	check = 1;
	check = mlx_load_wall(txr, check);
	check = mlx_load_exit(txr, check);
	(!(txr->player = mlx_load_png(PLAYER))) && (check = 0);
	(!(txr->collect = mlx_load_png(COLLECT))) && (check = 0);
	(!(txr->ground[GR] = mlx_load_png(GROUND))) && (check = 0);
	return (check);
}

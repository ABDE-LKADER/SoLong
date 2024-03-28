/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/27 16:43:11 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "mylib.h"
# include <fcntl.h>
# include <math.h>
# include <MLX42.h>

typedef struct s_map
{
	int		len;
	int		exit;
	int		width;
	int		height;
	int		player;
	int		collect;
	int		unwanted;
	char	up;
	char	down;
	char	left;
	char	right;
	char	**map;
}		map_t;

typedef struct s_txr
{
	mlx_texture_t	*exit[8];
	mlx_texture_t	*wall[12];
	mlx_texture_t	*ground[2];
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
}		t_txr;

typedef struct s_img
{
	mlx_image_t	*exit[8];
	mlx_image_t	*wall[12];
	mlx_image_t	*ground[2];
	mlx_image_t	*player;
	mlx_image_t	*collect;
	int		width;
	int		height;
}		t_img;

typedef struct s_data
{
	mlx_t	*mlx;
	map_t	map;
	t_txr	txr;
	t_img	img;
	int		moves;
	int		pos_x;
	int		pos_y;
	int		exit_x;
	int		exit_y;
}			t_data;

# define TILTEL "so_long"

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define TRUE 1
# define FALSE 0
# define DM 60

# define WA 0
# define W0 1
# define W2 2
# define WE 3
# define WL 4
# define WR 5
# define WU 6
# define WD 7
# define DL 8
# define UL 9
# define DR 10
# define UR 11

# define EX 0
# define E0 1
# define E1 2
# define E2 3
# define E3 4
# define E4 5
# define E5 6
# define E6 7

# define GR 0
# define GE 1

# define ESC 53
# define KLF 123
# define KRH 124
# define KDW 125
# define KUP 126

# define WALL "textures/wall.png"
# define WALL0 "textures/wall0.png"
# define WALL2 "textures/wall2.png"
# define WALL_E "textures/wall_e.png"
# define WALL_L "textures/wall_l.png"
# define WALL_R "textures/wall_r.png"
# define WALL_U "textures/wall_u.png"
# define WALL_D "textures/wall_d.png"
# define WALL_DL "textures/wall_dl.png"
# define WALL_UL "textures/wall_ul.png"
# define WALL_DR "textures/wall_dr.png"
# define WALL_UR "textures/wall_ur.png"

# define EXIT "textures/exit.png"
# define EXIT0 "textures/exit0.png"
# define EXIT1 "textures/exit1.png"
# define EXIT2 "textures/exit2.png"
# define EXIT3 "textures/exit3.png"
# define EXIT4 "textures/exit4.png"
# define EXIT5 "textures/exit5.png"
# define EXIT6 "textures/exit6.png"

# define GROUND "textures/ground.png"
# define GROUND_E "textures/ground_e.png"

# define PLAYER "textures/player.png"
# define COLLECT "textures/collect.png"

int		set_exit(t_data *data);
void	exit_game(t_data *data);
int		mlx_init_img(t_data *data);
int		mlx_load_img(t_txr *txr);
void	mlx_message_error(int set);
int		check_collect(t_data *data);
int		destroy_notify(t_data *data);
void	cleanup(char **s, t_data *data);
int		map_status(t_data *data, int key);
int		set_wall(t_data *data, int x, int y);
void	mlx_parce_input(int ac, char **av, map_t *map);
void	set_ground(t_data *data, int x, int y, int set);
void	mlx_put_img(t_data *data, int x, int y, int set);
void	mlx_move_player(mlx_key_data_t key, void *param);

#endif

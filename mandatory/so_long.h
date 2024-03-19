/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/19 11:45:58 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "mylib.h"
# include <fcntl.h>
# include <mlx.h>

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
}		t_map;

typedef struct s_img
{
	void	*wall;
	void	*wall0;
	void	*wall2;
	void	*wall_e;
	void	*exit;
	void	*wall_l;
	void	*wall_r;
	void	*wall_u;
	void	*wall_d;
	void	*wall_dl;
	void	*wall_ul;
	void	*wall_dr;
	void	*wall_ur;
	void	*ground;
	void	*player;
	void	*collect;
	int		width;
	int		height;
}		t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_map	map;
	t_img	img;
	int		pos_x;
	int		pos_y;
}			t_data;

# define TRUE 1
# define FALSE 0
# define DIMO 48

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define TILTEL "so_long"

# define WALL "textures/wall.xpm"
# define WALL0 "textures/wall0.xpm"
# define WALL2 "textures/wall2.xpm"
# define WALL_E "textures/wall_e.xpm"
# define WALL_L "textures/wall_l.xpm"
# define WALL_R "textures/wall_r.xpm"
# define WALL_U "textures/wall_u.xpm"
# define WALL_D "textures/wall_d.xpm"
# define WALL_DL "textures/wall_dl.xpm"
# define WALL_UL "textures/wall_ul.xpm"
# define WALL_DR "textures/wall_dr.xpm"
# define WALL_UR "textures/wall_ur.xpm"

# define GROUND "textures/ground.xpm"
# define PLAYER "textures/player.xpm"
# define COLLECT "textures/collect.xpm"
# define EXIT "textures/exit.xpm"

void	mlx_message_error(int set);
void	exit_game(t_data	*data);
int		destroy_notify(t_data *data);
void	cleanup(char **s, t_data *data);
int		map_status(t_data *data, int key);
int		mlx_move_player(int key, t_data	*data);
void	mlx_parce_input(int ac, char **av, t_map *map);
void	mlx_put_img(t_data *data, int x, int y, int set);

#endif

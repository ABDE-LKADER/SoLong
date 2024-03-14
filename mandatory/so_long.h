/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/14 11:27:03 by abadouab         ###   ########.fr       */
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
	void	*exit;
	void	*wall2;
	void	*ground;
	void	*p_left;
	void	*p_right;
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
# define DIMO 32

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define TILTEL "so_long"
# define WALL "textures/wall.xpm"
# define WALL2 "textures/wall2.xpm"
# define GROUND "textures/ground.xpm"
# define P_LEFT "textures/p_left.xpm"
# define P_RIGHT "textures/p_right.xpm"
# define COLLECT "textures/collect.xpm"
# define EXIT "textures/close_portal.xpm"

int		map_status(t_data *data);
void	mlx_message_error(int set);
void	exit_game(t_data	*data);
int		destroy_notify(t_data *data);
void	cleanup(char **s, t_data *data);
int		mlx_move_player(int key, t_data	*data);
void	mlx_parce_input(int ac, char **av, t_map *map);
void	mlx_put_img(t_data *data, int x, int y, int set);

#endif

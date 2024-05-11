/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 15:02:22 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "mylib.h"
# include <fcntl.h>
# include <mlx.h>

///////////////// HEAP_CLEANER /////////////////

typedef struct s_allocate
{
	void				*block;
	struct s_allocate	*next;
}						t_allocate;

void	cleanup(t_allocate **collec);
void	*allocate(t_allocate **collec, size_t count, size_t size);

///////////////// SO_LONG MACROS /////////////////

# define TILTEL "so_long"

# define GRN "\033[1;32m"
# define YLW "\033[1;33m"
# define RED "\033[1;31m"
# define RST "\033[0m"

# define TRUE 1
# define FALSE 0
# define DM 60

# define KEY_ESCAPE 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

# define EXIT1 "textures/EXIT1.xpm"
# define EXIT2 "textures/EXIT2.xpm"
# define EXIT3 "textures/EXIT3.xpm"
# define EXIT4 "textures/EXIT4.xpm"
# define EXIT5 "textures/EXIT5.xpm"
# define EXIT6 "textures/EXIT6.xpm"
# define EXIT7 "textures/EXIT7.xpm"
# define EXIT8 "textures/EXIT8.xpm"
# define FIRE1 "textures/FIRE1.xpm"
# define FIRE2 "textures/FIRE2.xpm"
# define FIRE3 "textures/FIRE3.xpm"
# define FIRE4 "textures/FIRE4.xpm"
# define FIRE5 "textures/FIRE5.xpm"
# define FIRE6 "textures/FIRE6.xpm"
# define FIRE7 "textures/FIRE7.xpm"
# define FIRE8 "textures/FIRE8.xpm"
# define WALL1 "textures/WALL1.xpm"
# define WALL2 "textures/WALL2.xpm"
# define WALL3 "textures/WALL3.xpm"
# define WALL4 "textures/WALL4.xpm"
# define WALL5 "textures/WALL5.xpm"
# define WALL6 "textures/WALL6.xpm"
# define WALL7 "textures/WALL7.xpm"
# define WALL8 "textures/WALL8.xpm"
# define FALL1 "textures/FALL1.xpm"
# define FALL2 "textures/FALL2.xpm"
# define IDLE1 "textures/IDLE1.xpm"
# define IDLE2 "textures/IDLE2.xpm"
# define IDLE3 "textures/IDLE3.xpm"
# define IDLE4 "textures/IDLE4.xpm"
# define IDLE5 "textures/IDLE5.xpm"
# define IDLE6 "textures/IDLE6.xpm"
# define IDLE7 "textures/IDLE7.xpm"
# define IDLE8 "textures/IDLE8.xpm"
# define RIGHT1 "textures/RIGHT1.xpm"
# define RIGHT2 "textures/RIGHT2.xpm"
# define RIGHT3 "textures/RIGHT3.xpm"
# define RIGHT4 "textures/RIGHT4.xpm"
# define RIGHT5 "textures/RIGHT5.xpm"
# define RIGHT6 "textures/RIGHT6.xpm"
# define RIGHT7 "textures/RIGHT7.xpm"
# define RIGHT8 "textures/RIGHT8.xpm"
# define SPACE1 "textures/SPACE1.xpm"
# define SPACE2 "textures/SPACE2.xpm"
# define SPACE3 "textures/SPACE3.xpm"
# define SPACE4 "textures/SPACE4.xpm"
# define GROUND "textures/GROUND.xpm"
# define PLAYER "textures/PLAYER.xpm"

///////////////// SO_LONG STRUCTS /////////////////

typedef struct s_map
{
	int				len;
	int				exit;
	int				width;
	int				height;
	int				player;
	int				collect;
	int				unwanted;
	char			up;
	char			down;
	char			left;
	char			right;
	char			**map;
	char			**flood;
}					t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			map;
	int				width;
	int				height;
	int				steps;
	int				pos_x;
	int				pos_y;
	int				exit_x;
	int				exit_y;
	t_allocate		*leak;
}					t_data;

///////////////// SO_LONG PROTOTYPES /////////////////

void	exit_game(t_data *data);
void	init_data(t_data *data);
void	mlx_message_error(int set);
void	mlx_draw_string(t_data *data);
int		map_status(t_map map, int key);
int		mlx_destroy_notify(t_data *data);
int		checker_set(char **map, char set);
void	mlx_move_up(t_data *data, int key);
void	set_wall(t_data *data, int x, int y);
void	mlx_move_down(t_data *data, int key);
// void	mlx_move_left(t_data *data, int key);
void	mlx_move_right(t_data *data, int key);
void	mlx_sync_frame(t_data *data, int key);
int		mlx_move_player(int key, void *param);
void	cleaning(t_allocate **leak, t_data *data);
void	mlx_idle_effects(t_data *data, int count);
void	mlx_exit_effects(t_data *data, int count);
void	flood_fill(char **map, int pos_x, int pos_y);
void	mlx_parce_input(int ac, char **av, t_data *data);
void	mlx_put_img(t_data *data, char *path, int x, int y);
void	mlx_fire_effects(t_data *data, t_map *map, int count);

#endif

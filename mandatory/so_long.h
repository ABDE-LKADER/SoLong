/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 17:44:07 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "mylib.h"
# include <fcntl.h>
# include <MLX42.h>

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

# define GR 0
# define PL 1
# define E1 2
# define E2 3
# define E3 4
# define E4 5
# define E5 6
# define E6 7
# define E7 8
# define E8 9
# define F1 10
# define F2 11
# define F3 12
# define F4 13
# define F5 14
# define F6 15
# define F7 16
# define F8 17
# define W1 18
# define W2 19
# define W3 20
# define W4 21
# define W5 22
# define W6 23
# define W7 24
# define W8 25
# define S1 26
# define S2 27
# define S3 28
# define S4 29
# define FN 30

# define EXIT1 "textures/EXIT1.png"
# define EXIT2 "textures/EXIT2.png"
# define EXIT3 "textures/EXIT3.png"
# define EXIT4 "textures/EXIT4.png"
# define EXIT5 "textures/EXIT5.png"
# define EXIT6 "textures/EXIT6.png"
# define EXIT7 "textures/EXIT7.png"
# define EXIT8 "textures/EXIT8.png"
# define FIRE1 "textures/FIRE1.png"
# define FIRE2 "textures/FIRE2.png"
# define FIRE3 "textures/FIRE3.png"
# define FIRE4 "textures/FIRE4.png"
# define FIRE5 "textures/FIRE5.png"
# define FIRE6 "textures/FIRE6.png"
# define FIRE7 "textures/FIRE7.png"
# define FIRE8 "textures/FIRE8.png"
# define WALL1 "textures/WALL1.png"
# define WALL2 "textures/WALL2.png"
# define WALL3 "textures/WALL3.png"
# define WALL4 "textures/WALL4.png"
# define WALL5 "textures/WALL5.png"
# define WALL6 "textures/WALL6.png"
# define WALL7 "textures/WALL7.png"
# define WALL8 "textures/WALL8.png"
# define SPACE1 "textures/SPACE1.png"
# define SPACE2 "textures/SPACE2.png"
# define SPACE3 "textures/SPACE3.png"
# define SPACE4 "textures/SPACE4.png"
# define GROUND "textures/GROUND.png"
# define PLAYER "textures/PLAYER.png"

///////////////// SO_LONG STRUCTS /////////////////

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

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
	mlx_t			*mlx;
	t_map			map;
	int				set;
	int				moves;
	int				pos_x;
	int				pos_y;
	int				exit_x;
	int				exit_y;
	int				timer;
	int				count;
	t_allocate		*leak;
	mlx_image_t		*img[FN];
}					t_data;

///////////////// SO_LONG PROTOTYPES /////////////////

void	init_data(t_data *data);
void	exit_game(t_data *data);
void	mlx_init_img(t_data *data);
void	mlx_message_error(int set);
void	mlx_do_effects(void *param);
int		checker_set(char **map, char set);
void	moving(t_data *data, int direction);
void	cleaning(t_allocate **leak, t_data *data);
int		map_status(t_map map, mlx_key_data_t key);
void	flood_fill(char **map, int pos_x, int pos_y);
void	mlx_parce_input(int ac, char **av, t_data *data);
void	mlx_move_player(mlx_key_data_t key, void *param);
void	set_exit(t_data *data, mlx_image_t **img, int x, int y);
void	set_wall(t_data *data, mlx_image_t **img, int x, int y);

#endif

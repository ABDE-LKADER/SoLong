/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/10 08:52:36 by abadouab         ###   ########.fr       */
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
	char    **map;
}		t_map;

typedef struct s_img
{
	void	*wall;
	void	*exit;
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
	t_map	*map;
	t_img	*img;
}           t_data;

# define TILTEL "so_long"
# define WALL "textures/brick.xpm"
# define GROUND "textures/brick.xpm"
# define PLAYER "textures/brick.xpm"
# define EXIT "textures/brick.xpm"
# define COLLECT "textures/brick.xpm"

void	mlx_message_error(int set);
void	mlx_parce_input(int ac, char **av, t_map *map);

#endif

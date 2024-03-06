/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 13:46:01 by abadouab         ###   ########.fr       */
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
    int     exit;
    int     width;
    int     height;
    int     player;
    int     collect;
    int     unwanted;
    char    **map;
    t_list  *list;
}		t_map;

typedef struct s_img
{
	void	*wall;
    int     width;
    int     height;
}		t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
}           t_data;

# define TILTEL "so_long"
# define WALL "textures/brick.xpm"

void	mlx_message_error(int set);
void	mlx_parce_input(int ac, char **av, t_map *res);

#endif

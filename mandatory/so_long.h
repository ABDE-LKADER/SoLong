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

typedef struct s_res
{
    int     with;
    int     height;
}		t_res;

typedef struct s_data
{
	void	*mlx;
	void	*wall;
	void	*mlx_win;
}           t_data;

# define TILTEL "so_long"
# define WALL "textures/brick.xpm"

void	message_error(int set);
void	parce_in(int ac, char **av);

#endif

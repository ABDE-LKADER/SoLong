/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/22 17:18:48 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	mlx_get_positin(t_data *data, t_pos **pos, int x, int y)
{
	t_pos	*new;

	new = allocate(&data->leak, TRUE, sizeof(t_pos));
	if (!pos || !new)
		(cleaning(&data->leak, data), mlx_message_error(5, NULL));
	new->ex = x;
	new->ey = y;
	new->next = NULL;
	new->next = (*pos);
	(*pos) = new;
}

void	mlx_enemy_positions(t_data *data, t_pos **pos)
{
	int		ex;
	int		ey;
	char	**map;

	(TRUE) && (ey = -1, map = data->map.map);
	while (map[++ey])
	{
		ex = -1;
		while (map[ey][++ex])
		{
			if (map[ey][ex] == 'N')
				mlx_get_positin(data, pos, ex, ey);
		}
	}
}

static void	mlx_put_attack(t_data *data, t_pos *pos, int set, int dir)
{
	void	*img;
	char	*path;

	(!dir && set == 1) && (path = BACK1);
	(!dir && set == 2) && (path = BACK2);
	(!dir && set == 3) && (path = BACK3);
	(!dir && set == 4) && (path = BACK4);
	(!dir && set == 5) && (path = BACK5);
	(!dir && set == 6) && (path = BACK6);
	(dir && set == 1) && (path = ENEMY1);
	(dir && set == 2) && (path = ENEMY2);
	(dir && set == 3) && (path = ENEMY3);
	(dir && set == 4) && (path = ENEMY4);
	(dir && set == 5) && (path = ENEMY5);
	(dir && set == 6) && (path = ENEMY6);
	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), mlx_message_error(4, path));
	mlx_put_image_to_window(data->mlx,
		data->win, img, pos->ex * DM, pos->ey * DM);
	mlx_destroy_image(data->mlx, img);
}

static void	mlx_enemy_handler(t_data *data, t_pos *pos, int set)
{
	static int		dir;

	mlx_put_img(data, GROUND, pos->ex * DM, pos->ey * DM);
	if (pos->ex > data->pos_x
		&& !ft_strchr("1CEN", data->map.map[pos->ey][pos->ex - 1]))
		(TRUE) && (data->map.map[pos->ey][pos->ex--] = '0',
			data->map.map[pos->ey][pos->ex] = 'N', dir = 1);
	else if (pos->ey > data->pos_y
		&& !ft_strchr("1CEN", data->map.map[pos->ey - 1][pos->ex]))
		(TRUE) && (data->map.map[pos->ey--][pos->ex] = '0',
			data->map.map[pos->ey][pos->ex] = 'N');
	else if (pos->ex < data->pos_x
		&& !ft_strchr("1CEN", data->map.map[pos->ey][pos->ex + 1]))
		(TRUE) && (data->map.map[pos->ey][pos->ex++] = '0',
			data->map.map[pos->ey][pos->ex] = 'N', dir = 0);
	else if (pos->ey < data->pos_y
		&& !ft_strchr("1CEN", data->map.map[pos->ey + 1][pos->ex]))
		(TRUE) && (data->map.map[pos->ey++][pos->ex] = '0',
			data->map.map[pos->ey][pos->ex] = 'N');
	if (pos->ex == data->pos_x && pos->ey == data->pos_y)
		exit_game(data, FALSE);
	mlx_put_img(data, GROUND, pos->ex * DM, pos->ey * DM);
	mlx_put_attack(data, pos, set, dir);
}

void	mlx_enemy_attack(t_data *data, t_pos *pos, int count)
{
	t_pos		*loop;
	static int	set;

	if (++set <= 6 && !(count % 2919))
	{
		loop = pos;
		while (loop)
		{
			mlx_enemy_handler(data, loop, set);
			loop = loop->next;
		}
	}
	(set == 6) && (set = 0);
}

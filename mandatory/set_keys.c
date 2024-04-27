/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 16:03:51 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *data)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

int	check_collect(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (data->map.map[y][x] == 'C')
				return (1);
		}
	}
	return (0);
}

int	map_status(t_data *data, int key)
{
	if (check_collect(data))
		return (1);
	if ((ft_strchr("E", data->map.up) && key == MLX_KEY_UP)
		|| (ft_strchr("E", data->map.down) && key == MLX_KEY_DOWN)
		|| (ft_strchr("E", data->map.left) && key == MLX_KEY_LEFT)
		|| (ft_strchr("E", data->map.right) && key == MLX_KEY_RIGHT))
		return (0);
	return (1);
}

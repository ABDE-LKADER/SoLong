/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_attack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:46:19 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/15 11:41:21 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	mlx_enemy_attack(t_data *data, t_map *map, int count)
{
	(void)count;
	map->up = map->map[data->pos_y - 1][data->pos_x];
	map->down = map->map[data->pos_y + 1][data->pos_x];
	map->left = map->map[data->pos_y][data->pos_x - 1];
	map->right = map->map[data->pos_y][data->pos_x + 1];
	if (!ft_strchr("1CE", data->map.up))
		;
	else if (!ft_strchr("1CE", data->map.down))
		;
	else if (!ft_strchr("1CE", data->map.left))
		;
	else if (!ft_strchr("1CE", data->map.right))
		;
	// if ((ft_strchr("P", data->map.up) || ft_strchr("P", data->map.down)
	// 	|| ft_strchr("P", data->map.left) || ft_strchr("P", data->map.right)))
	// 	exit_game(data, KEY_ESCAPE);
}

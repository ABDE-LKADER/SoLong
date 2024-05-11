/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 13:03:38 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_data *data)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

int	mlx_destroy_notify(t_data *data)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

void	init_data(t_data *data)
{
	data->map.unwanted = 0;
	data->map.player = 0;
	data->leak = NULL;
	data->exit_y = 0;
	data->pos_x = 0;
	data->pos_x = 0;
	data->steps = 0;
	data->exit_x = 0;
	data->map.len = 0;
	data->map.exit = 0;
	data->map.width = 0;
	data->map.height = 0;
	data->map.collect = 0;
}

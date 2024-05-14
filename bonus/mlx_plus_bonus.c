/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plus_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/14 22:41:28 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_game(t_data *data, int key)
{
	if (key != KEY_ESCAPE)
		ft_printf(GRN"moves: %d\n"RST, data->steps++);
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

int	mlx_destroy_notify(t_data *data)
{
	cleaning(&data->leak, data);
	exit(EXIT_SUCCESS);
}

void	cleaning(t_allocate **leak, t_data *data)
{
	if (data->mlx && data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	cleanup(leak);
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
	data->collect = 0;
	data->map.len = 0;
	data->map.exit = 0;
	data->map.width = 0;
	data->map.height = 0;
	data->map.collect = 0;
}

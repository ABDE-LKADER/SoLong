/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_plus_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/12 15:04:01 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	cleaning(t_allocate **leak, t_data *data)
{
	if (data->mlx && data->win)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	cleanup(leak);
}

void	mlx_message_error(int set)
{
	if (set == 0)
		ft_putstr_fd(RED"Error:\n"YLW"Usage: "
			RST"./so_long <filename.ber>\n", 2);
	else if (set == 1)
		ft_putstr_fd(RED"Error:\n"RST"Input must have "
			YLW"\".ber\""RST" extension.\n", 2);
	else if (set == 2)
		ft_putstr_fd(RED"Error:\n"YLW"<file>"RST" not found.\n", 2);
	else if (set == 3)
		ft_putstr_fd(RED"Error:\n"RST"Invalid "YLW"<Map>"RST"\n", 2);
	exit(EXIT_FAILURE);
}

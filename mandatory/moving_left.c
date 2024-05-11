/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:26 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 11:56:57 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	mlx_move_left(t_data *data)
// {
// 	int		px;
// 	int		py;
// 	int		move;
// 	int		count;
// 	int		index;

// 	(TRUE) && (move = 7, index = R1,
// 		px = data->pos_x * DM, py = data->pos_y * DM);
// 	while (index <= R8)
// 	{
// 		mlx_put_img(data, GROUND, px, py);
// 		mlx_put_img(data, GROUND, px - move, py);
// 		mlx_put_image_to_window(data->mlx, data->win,
// 			data->img[index++], px - move, py);
// 		mlx_do_sync(data->mlx);
// 		(index == R8) && (--data->pos_x);
// 		if (data->map.map[data->pos_y][data->pos_x] == 'C')
// 			data->map.collect--;
// 		(index == R8) && (data->map.map[data->pos_y][data->pos_x] = 'P');
// 		(index == R8) && (ft_printf(GRN"moves: %d\n"RST, data->steps++));
// 		if (index == R8)
// 			mlx_draw_string(data);
// 		move += 7;
// 	}
// }

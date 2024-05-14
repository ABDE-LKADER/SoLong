/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/14 18:29:52 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	checker(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &data->height, &data->width);
	if (!img)
		(cleaning(&data->leak, data), mlx_message_error(4, path));
	mlx_destroy_image(data->mlx, img);
}

void	mlx_checker(t_data *data)
{
	(checker(data, EXIT1), checker(data, EXIT2), checker(data, EXIT3));
	(checker(data, EXIT4), checker(data, EXIT5), checker(data, EXIT6));
	(checker(data, EXIT7), checker(data, EXIT8), checker(data, FIRE1));
	(checker(data, FIRE2), checker(data, FIRE3), checker(data, FIRE4));
	(checker(data, FIRE5), checker(data, FIRE6), checker(data, FIRE7));
	(checker(data, FIRE8), checker(data, WALL1), checker(data, WALL2));
	(checker(data, WALL3), checker(data, WALL4), checker(data, WALL5));
	(checker(data, WALL6), checker(data, WALL7), checker(data, WALL8));
	(checker(data, IDLE1), checker(data, IDLE2), checker(data, IDLE3));
	(checker(data, IDLE4), checker(data, IDLE5), checker(data, IDLE6));
	(checker(data, IDLE7), checker(data, IDLE8), checker(data, LEFT1));
	(checker(data, LEFT2), checker(data, LEFT3), checker(data, LEFT4));
	(checker(data, LEFT5), checker(data, LEFT6), checker(data, LEFT7));
	(checker(data, LEFT8), checker(data, FALL1), checker(data, FALL2));
	(checker(data, JUMP1), checker(data, JUMP2), checker(data, SPACE1));
	(checker(data, SPACE2), checker(data, SPACE3), checker(data, SPACE4));
	(checker(data, RIGHT1), checker(data, RIGHT2), checker(data, RIGHT3));
	(checker(data, RIGHT4), checker(data, RIGHT5), checker(data, RIGHT6));
	(checker(data, RIGHT7), checker(data, RIGHT8), checker(data, GROUND));
}

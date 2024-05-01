/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:37:35 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 16:08:50 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *data)
{
	data->leak = NULL;
	data->set = 0;
	data->steps = 0;
	data->count = 0;
	data->pos_x = 0;
	data->pos_x = 0;
	data->exit_x = 0;
	data->exit_y = 0;
}

void	cleaning(t_allocate **leak, t_data *data)
{
	if (data)
		mlx_close_window(data->mlx);
	cleanup(leak);
}

void	*allocate(t_allocate **collec, size_t count, size_t size)
{
	t_allocate	*new;

	new = malloc(sizeof(t_allocate));
	if (!new)
		return (NULL);
	new->block = ft_calloc(count, size);
	if (!new->block)
		return (free(new), NULL);
	(TRUE) && (new->next = *collec, *collec = new);
	return (new->block);
}

void	cleanup(t_allocate **collec)
{
	t_allocate	*set;
	t_allocate	*next;

	set = *collec;
	while (set)
	{
		next = set->next;
		if (set->block)
			free(set->block);
		(free(set), set = next);
	}
	*collec = NULL;
}

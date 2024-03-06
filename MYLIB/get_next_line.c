/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:10:23 by abadouab          #+#    #+#             */
/*   Updated: 2024/01/20 15:09:37 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

char	*get_read(int fd, char *save)
{
	char	*load;
	int		bytes;

	bytes = 1;
	load = malloc((size_t)BUFFER_SIZE + 1);
	if (!load)
		return (NULL);
	while (ft_search(save) && bytes)
	{
		bytes = read(fd, load, BUFFER_SIZE);
		if (bytes == -1)
			return (free(load), NULL);
		load[bytes] = '\0';
		save = join_strings(save, load);
	}
	return (free(load), save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX
		|| read(fd, save, 0) == -1)
		return (NULL);
	save = get_read(fd, save);
	if (!save)
		return (NULL);
	line = strdup_line(save);
	save = strdup_next(save);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_parce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/05/11 16:53:40 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	mlx_check_map(t_data *data, t_map *map, char *line, char *next)
{
	int		index;
	int		invalid;

	(TRUE) && (index = 0, invalid = 0);
	(line) && (map->height++);
	(next) && (map->len = ft_strlen(next));
	(ft_strchr(next, '\n')) && (map->len--);
	(line && (map->width != map->len || line[0] != '1'
			|| line[map->width - 1] != '1')) && (map->unwanted = 1);
	while (line && line[index] && line[index] != '\n')
	{
		(line[index] == 'E') && (map->exit++, data->exit_x = index,
			data->exit_y = map->height - 1);
		(line[index] == 'P') && (map->player++, data->pos_x = index,
			data->pos_y = map->height - 1);
		(line[index] == 'C') && (map->collect++);
		(line[index] != '1' && !next) && (map->unwanted = 1);
		(!ft_strchr("01EPC", line[index])) && (map->unwanted = 1);
		(line[index] != '1' && map->height == 1) && (map->unwanted = 1);
		index++;
	}
	(!map->collect) && (invalid = 1);
	(map->exit != 1) && (invalid = 1);
	(map->player != 1) && (invalid = 1);
	return (invalid);
}

static void	mlx_map_init(t_data *data, t_map *map, int fd)
{
	int			len;
	int			index;
	char		*line;

	index = 0;
	len = map->width + 1;
	line = get_next_line(fd);
	map->map = allocate(&data->leak, (map->height + 1), sizeof(char **));
	map->flood = allocate(&data->leak, (map->height + 1), sizeof(char **));
	while (line)
	{
		map->map[index] = allocate(&data->leak, len, sizeof(char *));
		map->flood[index] = allocate(&data->leak, len, sizeof(char *));
		ft_strlcpy(map->map[index], line, len);
		ft_strlcpy(map->flood[index], line, len);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	map->map[index] = NULL;
	map->flood[index] = NULL;
}

static void	mlx_map_resolution(t_data *data, t_map *map, int fd)
{
	int		one;
	char	*line;
	char	*next;

	line = get_next_line(fd);
	if (!line)
		mlx_message_error(3);
	map->len = ft_strlen(line);
	(ft_strchr(line, '\n')) && (map->len--);
	(1) && (one = 0, map->width = map->len);
	while (line)
	{
		(one) && (line = next);
		next = get_next_line(fd);
		if ((!line && map->height <= 2) || map->unwanted)
		{
			free(line);
			mlx_message_error(3);
		}
		(1) && (mlx_check_map(data, map, line, next), free(line), one = 1);
	}
	if (mlx_check_map(data, map, NULL, NULL))
		mlx_message_error(3);
}

void	mlx_parce_input(int ac, char **av, t_data *data)
{
	int		fd;
	char	*extn;

	init_data(data);
	if (ac != 2)
		mlx_message_error(0);
	extn = ft_strrchr(av[1], '.');
	if (!extn || ft_strncmp(extn, ".ber", ft_strlen(extn)))
		mlx_message_error(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		mlx_message_error(2);
	mlx_map_resolution(data, &data->map, fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		mlx_message_error(2);
	mlx_map_init(data, &data->map, fd);
	close(fd);
	flood_fill(data->map.flood, data->pos_x, data->pos_y);
	if (checker_set(data->map.flood, 'C')
		|| checker_set(data->map.flood, 'E'))
		mlx_message_error(3);
}

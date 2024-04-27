/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/04/27 16:23:43 by abadouab         ###   ########.fr       */
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
		ft_putstr_fd(RED"Error:\n"RST"Invalid "YLW"<Map>"RST".\n", 2);
	else if (set == 4)
		ft_putstr_fd(RED"Error:\n"RST"Invalid "YLW"????"RST".\n", 2);
	exit(EXIT_FAILURE);
}

static int	mlx_check_map(t_map *map, char *line, char *next)
{
	int	invalid;

	invalid = 0;
	if (line)
		map->height++;
	(next) && (map->len = ft_strlen(next));
	(ft_strchr(next, '\n')) && (map->len--);
	(line && (map->width != map->len || line[0] != '1'
			|| line[map->width - 1] != '1')) && (map->unwanted = 1);
	while (line && *line && *line != '\n')
	{
		(*line == 'E') && (map->exit++);
		(*line == 'P') && (map->player++);
		(*line == 'C') && (map->collect++);
		(*line != '1' && !next) && (map->unwanted = 1);
		(!ft_strchr("01EPC", *line)) && (map->unwanted = 1);
		(*line != '1' && map->height == 1) && (map->unwanted = 1);
		line++;
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
	map->map = allocate(&data->leak, map->height, sizeof(char **));
	map->flood = allocate(&data->leak, map->height, sizeof(char **));
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

static void	mlx_map_resolution(t_map *map, int fd)
{
	int		one;
	char	*line;
	char	*next;

	line = get_next_line(fd);
	if (!line)
		mlx_message_error(3);
	map->len = ft_strlen(line);
	(ft_strchr(line, '\n')) && (map->len--);
	(1) && (one = 0, map->exit = 0, map->player = 0, map->collect = 0,
		map->unwanted = 0, map->height = 0, map->width = map->len);
	while (line)
	{
		(one) && (line = next);
		next = get_next_line(fd);
		if ((!line && map->height <= 2) || map->unwanted)
		{
			free(line);
			mlx_message_error(3);
		}
		(1) && (mlx_check_map(map, line, next), free(line), one = 1);
	}
	if (mlx_check_map(map, NULL, NULL))
		mlx_message_error(3);
}

void	mlx_parce_input(int ac, char **av, t_data *data)
{
	int		fd;
	char	*extn;

	if (ac != 2)
		mlx_message_error(0);
	extn = ft_strrchr(av[1], '.');
	if (!extn || ft_strncmp(extn, ".ber", ft_strlen(extn)))
		mlx_message_error(1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		mlx_message_error(2);
	mlx_map_resolution(&data->map, fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		mlx_message_error(2);
	mlx_map_init(data, &data->map, fd);
	close(fd);
}

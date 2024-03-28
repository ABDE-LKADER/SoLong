/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/03/27 15:57:35 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_message_error(int set)
{
	if (set == 0)
		write(2, RED"Error:\n"YLW"Usage: "RST"./so_long <filename.ber>\n", 57);
	else if (set == 1)
		write(2, RED"Error:\n"RST"Input must have "YLW"\".ber\""RST" extension.\n", 63);
	else if (set == 2)
		write(2, RED"Error:\n"YLW"<file>"RST" not found.\n", 50);
	else if (set == 3)
		write(2, RED"Error:\n"RST"Invalid "YLW"<Map>"RST".\n", 44);
	else if (set == 4)
		write(2, RED"Error:\n"RST"Invalid "YLW"????"RST".\n", 44);
	exit(EXIT_FAILURE);
}

static int	mlx_check_map(map_t *map, char *line, char *next)
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

static void	mlx_map_init(map_t *map, int fd)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	map->map = malloc(map->height * sizeof(char **));
	while (line)
	{
		map->map[index] = malloc(map->width + 1 * sizeof(char *));
		ft_strlcpy(map->map[index], line, map->width + 1);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	map->map[index] = NULL;
}

static void	mlx_map_resolution(map_t *map, int fd)
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

void	mlx_parce_input(int ac, char **av, map_t *map)
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
	mlx_map_resolution(map, fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		mlx_message_error(2);
	mlx_map_init(map, fd);
	close(fd);
}

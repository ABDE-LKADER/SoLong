/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadouab <abadouab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:18:37 by abadouab          #+#    #+#             */
/*   Updated: 2024/02/26 13:46:01 by abadouab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mlx_message_error(int set)
{
	if (set == 0)
		write(2, "\033[1;31mUsage: \033[0m./so_long <filename.ber>\n", 43);
	else if (set == 1)
		write(2, "\033[1;31mError: \033[0mInput must have \
		\".ber\" extension.\n", 52);
	else if (set == 2)
		write(2, "\033[1;31mError: \033[0m<file> not found\n", 35);
	else if (set == 3)
		write(2, "\033[1;31mError: \033[0m<Map> Invalid\n", 32);
	exit(EXIT_FAILURE);
}

static int mlx_check_map(t_map *map, char *line, char *next)
{
	int	invalid;

	invalid = 0;
	(next) && (map->len = ft_strlen(next));
	(ft_strchr(next, '\n')) && (map->len--);
	map->height++;
	if (line)
		(map->width != map->len || line[0] != '1' || line[map->width - 1] != '1')
		&& (map->unwanted = 1);
	while (line && *line && *line != '\n')
	{
		(*line == 'E') && (map->exit++);
		(*line == 'P') && (map->player++);
		(*line == 'C') && (map->collect++);
		(*line != '1' && map->height == 1) && (map->unwanted = 1);
		(*line != '1' && !next) && (map->unwanted = 1);
		(!ft_strchr("01EPC", *line)) && (map->unwanted = 1);
		line++;
	}
	(!map->collect) && (invalid = 1);
	(map->exit != 1) && (invalid = 1);
	(map->player != 1) && (invalid = 1);
}

static void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

static void	mlx_map_init(t_map *map)
{
	map->map = malloc(map->height * sizeof(char **));
	while (map->list->next)
	{
		*map->map = malloc(map->width * sizeof(char *));
		ft_strlcpy(*map->map, map->list->content, map->width + 1);
		map->list = map->list->next;
	}
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
	map->list = ft_lstnew(line);
	(ft_strchr(line, '\n')) && (map->len--);
	(1) && (one = 0, map->exit = 0, map->player = 0, map->collect = 0,
		map->unwanted = 0, map->height = 0, map->width = map->len);
	while (line)
	{
		(one) && (line = next);
		if (one)
			ft_lstadd_back(&map->list, ft_lstnew(line));
		next = get_next_line(fd);
		if ((!next && map->height <= 2) || map->unwanted)
			mlx_message_error(3);
		mlx_check_map(map, line, next);
		one = 1;
	}
	if (mlx_check_map(map, NULL, NULL))
			mlx_message_error(3);
}

void	mlx_parce_input(int ac, char **av, t_map *map)
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
	mlx_map_init(map);
	ft_lstclear(map->list, free);
	close(fd);
}

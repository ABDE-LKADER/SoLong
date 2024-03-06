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

void	message_error(int set)
{
	if (set == 0)
		write(2, "\033[1;31mUsage: \033[0m./so_long <filename.ber>\n", 43);
	else if (set == 1)
		write(2, "\033[1;31mError: \033[0mInput must have \".ber\" extension.\n", 52);
	else if (set == 2)
		write(2, "\033[1;31mError: \033[0m<file> not found\n", 35);
	exit(EXIT_FAILURE);
}

void	parce_in(int ac, char **av)
{
	int		file;
	char	*extn;

	if (ac != 2)
		message_error(0);
	extn = ft_strrchr(av[1], '.');
	if (!extn || ft_strncmp(extn, ".ber", ft_strlen(extn)))
		message_error(1);
	file = open(av[1], O_RDONLY);
	if (file == -1)
		message_error(2);
}

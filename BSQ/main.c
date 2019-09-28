/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:12:34 by mli               #+#    #+#             */
/*   Updated: 2019/09/29 00:48:04 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

#include <stdio.h>

int		ft_first_line(int fd, char *content, int size, char fills[4])
{
	int i;

	i = 0;
	while (*content >= '0' && *content <= '9')
	{
		size = (size * 10) + *content - '0';
		read(fd, content, 1);
	}
	while (*content != '\n')
	{
		fills[i++] = *content;
		read(fd, content, 1);
	}
	fills[i] = *content;
	return (size);
}

int		ft_is_map_ok(int fd)
{
	int		size;
	char	content;
	char	fills[4];

	if (!read(fd, &content, 1))
		return (0);
	size = ft_first_line(fd, &content, 0, fills);
	if (!size)
		return (0);
	while (read(fd, &content, 1))
	{
		if (content != fills[0] && content != fills[1] && content != '\n')
			return (0);
	
	
	}

	printf("Size: %d, and tab filled with %c%c%c'\\n'\n",
			size, fills[0], fills[1], fills[2]);
	return (1);

}

int		main(int argc, char **argv)
{
	int i;
	int fd;

	i = 0;
	if (argc == 1)
	{
		if (!ft_is_map_ok(0))
			write(2, "map error\n", 10);
	}
	else
		while (++i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
			{
				if (!ft_is_map_ok(fd))
					write(2, "map error\n", 10);
				close(fd);
			}
			if (i < argc - 1)
				write(1, "\n", 1);
		}
	return (0);
}

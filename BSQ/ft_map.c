/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:55:25 by mli               #+#    #+#             */
/*   Updated: 2019/10/02 23:25:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

void	ft_print_map(char **map, int size, int len)
{
	int i;

	i = -1;
	while (++i < size)
	{
		write(1, &(map[i][0]), len);
		write(1, "\n", 1);
	}
}

char	**ft_create_map_and_fill(int fd, int size, int len, char content)
{
	int		i;
	char	**map;

	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (++i < size)
		if (!(map[i] = (char *)malloc(sizeof(char) * len)))
			return (NULL);
	while (content != '\n')
		read(fd, &content, 1);
	i = -1;
	while (++i < size - 1)
	{
		read(fd, map[i], len - 1);
		map[i][len - 1] = '\0';
		read(fd, &content, 1);
	}
	map[i] = NULL;
	return (map);
}

int		ft_is_map_ok(int fd, int fd1)
{
	int		size;
	int		len;
	char	content;
	char	fills[4];
	char	**map;

	if (!read(fd, &content, 1))
		return (0);
	if (!(size = ft_first_line(fd, &content, 0, fills)))
		return (0);
	if (!(len = ft_map_len(fd, content, fills)))
		return (0);

	printf("Size: %d, len: %d, and tab filled with '%c%c%c' and '\\n'\n",
			size, len, fills[0], fills[1], fills[2]);

	read(fd1, &content, 1);
	if ((map = ft_create_map_and_fill(fd1, size + 1, len + 1, content)))
	{
//		ft_bsq(map, size, len, fills);
		ft_print_map(map, size, len);
	}
	return (1);
}

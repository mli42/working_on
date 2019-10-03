/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:12:34 by mli               #+#    #+#             */
/*   Updated: 2019/10/03 11:43:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

void	ft_more_args(int argc, char **argv, int i)
{
	int fd;
	int fd1;

	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		fd1 = open(argv[i], O_RDONLY);
		if (fd > 0 && fd1 > 0)
		{
			if (!ft_is_map_ok(fd, fd1))
				write(2, "map error\n", 10);
			close(fd);
			close(fd1);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
	}
}

char	**ft_only_one_arg(void)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	if (!(tab[0] = malloc(sizeof(char) * 2)))
		return (NULL);
	if (!(tab[1] = malloc(sizeof(char) * 7)))
		return (NULL);
	tab[0] = "b\0";
	tab[1] = "no_map\0";
	return (tab);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	content;
	char	**no_file;

	if (argc == 1)
	{
		no_file = ft_only_one_arg();
		fd = open(no_file[1], O_CREAT | O_WRONLY | O_TRUNC);
		if (!no_file || fd < 0)
			return (0);
		while (read(0, &content, 1))
			write(fd, &content, 1);
		close(fd);
		ft_more_args(2, no_file, 0);
	}
	else
		ft_more_args(argc, argv, 0);
	return (0);
}

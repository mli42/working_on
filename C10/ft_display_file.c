/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:22:42 by mli               #+#    #+#             */
/*   Updated: 2019/09/26 19:54:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

void	ft_display(int fd)
{
	char	content;

	while (read(fd, &content, 1))
		write(1, &content, 1);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			write(2, "Cannot read file.\n", 18);
		else
		{
			ft_display(fd);
			close(fd);
		}
	}
	return (0);
}

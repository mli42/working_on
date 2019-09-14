/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:22:31 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 18:32:31 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ulstr(char **argv)
{
	int i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			argv[1][i] += 32;
		else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] -= 32;
		i++;
	}
	i = 0;
	while (argv[1][i])
		write(1, &argv[1][i++], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv);
	write(1, "\n", 1);
	return (0);
}

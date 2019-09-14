/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mirror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:22:56 by mli               #+#    #+#             */
/*   Updated: 2019/07/23 17:04:45 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i;
	int k;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'm')
			{
				k = 'z' - (argv[1][i] - 'a');
				write(1, &k, 1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'M')
			{
				k = 'Z' - (argv[1][i] - 'A');
				write(1, &k, 1);
			}
			else if (argv[1][i] >= 'm' && argv[1][i] <= 'z')
			{
				k = 'a' - (argv[1][i] - 'z');
				write(1, &k, 1);
			}
			else if (argv[1][i] >= 'M' && argv[1][i] <= 'Z')
			{
				k = 'A' - (argv[1][i] - 'Z');
				write(1, &k, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

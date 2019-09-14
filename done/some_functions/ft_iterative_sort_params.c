/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_sort_params.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:32:49 by mli               #+#    #+#             */
/*   Updated: 2019/08/03 15:32:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_arg_cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (!s1[i])
			return (0);
		i++;
	}
	if (s1[i] - s2[i] > 0)
		return (1);
	else
		return (0);
}

void	ft_print_params(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			write(1, &argv[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	ft_sort_params(int argc, char **argv)
{
	int i;
	char *swap;

	while (argc > 1)
	{
		i = 1;
		while (i < argc - 1)
		{
			while (ft_arg_cmp(argv[i], argv[i + 1]))
			{
				swap = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = swap;
			}
			i++;
		}
		argc--;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_sort_params(argc, argv);
		ft_print_params(argv);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:40:54 by mli               #+#    #+#             */
/*   Updated: 2019/09/01 23:45:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>

void	ft_print(int *tab, int n)
{
	int to_print;

	while (--n >= 0)
	{
		to_print = tab[n] + 48;
		write(1, &to_print, 1);
	}
}

void	ft_print_combn(int n)
{
	int i;
	int tab[n];

	i = 0;
	tab[i] = n - 1;
//	while (tab[n - 1] <= (10 - n))
//	{
		i = -1;
		while (++i <= n - 2)
			tab[i + 1] = (tab[i] - 1);
		ft_print(tab, n);
//	}

	write(1, "\nEnd\n", 5);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(atoi(argv[1]));
	return (0);
}

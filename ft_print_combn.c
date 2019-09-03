/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:40:54 by mli               #+#    #+#             */
/*   Updated: 2019/09/02 23:43:50 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdlib.h>

void	ft_initialize(int *tab, int n)
{
	int i;

	i = 0;
	while (--n >= 0)
		tab[n] = (i++);
}

void	ft_print(int *tab, int n)
{
	int to_print;

	while (--n >= 0)
	{
		to_print = tab[n] + 48;
		write(1, &to_print, 1);
	}
}

int		ft_check(int *tab, int n)
{
	while (--n > 0)
		if (tab[n] >= tab[n - 1])
			return (0);
	return (1);
}

void	ft_print_combn(int n)
{
	int k;
	int tab[n];

	ft_initialize(tab, n);
	while (tab[n - 1] < (10 - n))
	{
			if (ft_check(tab, n))
			{
				ft_print(tab, n);
				write(1, ", ", 2);
			}
			k = 0;
			while ((tab[k] == (9 - k)) && (k < n))
				k++;
			// k tel que : tab[k] != max
			if ((k > 0) && (k < n))
			{
				tab[k]++;
				while (--k >= 0)
					tab[k] = tab[k + 1] + 1;
			}
			// On a aug devant et réinitialisé derrière
			else if (tab[0] < 9)
				tab[0]++;
	}
	ft_print(tab, n);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(atoi(argv[1]));
	return (0);
}

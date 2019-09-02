/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:40:54 by mli               #+#    #+#             */
/*   Updated: 2019/09/02 20:05:59 by mli              ###   ########.fr       */
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
	int i;
	int k;
	int tab[n];

	i = 0;
	k = 0;
	ft_initialize(tab, n);
	while (tab[n - 1] <= (10 - n))
	{
		while (tab[i] <= (9 - i) && (i < n - 1))
		{
			if (ft_check(tab, n))
			{
				ft_print(tab, n);
				if (tab[n - 1] < (10 - n))
					write(1, ", ", 2);
			}
			if (tab[i] == (9 - i) && (i < n - 1))
			{
				tab[i + 1]++;
				tab[i] = tab[i + 1] + 1;
			}
			// Then
			k = 0;
			while ((tab[i + k] == (9 - i)) && (i + k < n - 1))
				k++;
			// On a k tq => tab[i + k] != max
			while (k >= 0)
			{
				tab[i + k]++;
			}
			if (tab[i] != (9 - i) && (i < n - 1))
				tab[i]++;
		}
		break;
	}

	write(1, "\nEnd\n", 5);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(atoi(argv[1]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:03:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/03 19:42:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_test_fill(int tab[10]);
void    print_tab_tenxten(int tab[10]);

void	ft_initialize(int tab[10])
{
	int i;

	i = 0;
	while (i < 10)
		tab[i++] = 0;
}

void	ft_print_result(int tab[10])
{
	int i;
	int to_print;

	i = 0;
	while (i < 10)
	{
		to_print = tab[i++] + 48;
		write(1, &to_print, 1);
		if (i < 10)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int		ft_check(int tab[10], int i)
{
	int j;
	int k;

	j = 0;
	k = 1;
	// Check Ligne, No need Colonne
	while (j < 10)
	{
		if (i != j)
			if (tab[i] == tab[j])
				return (0);
		j++;
	}
	// Check Diagonales
	while (k < 10)
	{
		if (i - k >= 0)
			if ((tab[i - k] == tab[i] - k) || (tab[i - k] == tab[i] + k))
				return (0);
		if (i + k < 10)
			if ((tab[i + k] == tab[i] - k) || (tab[i + k] == tab[i] + k))
				return (0);
		k++;
	}
	return (1);
}

int		ft_backtracking(int tab[10], int i, int filling)
{

	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int		n;
	int		tab[10];

	n = 0;
	ft_initialize(tab);

//	ft_test_fill(tab);

//	ft_backtracking(tab, 0, 1);

	print_tab_tenxten(tab);
	write(1, "\n", 1);
	ft_print_result(tab);
	n++;
	return (n);
}

int		main(void)
{
	printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

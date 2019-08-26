/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ten_queen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:03:40 by mli               #+#    #+#             */
/*   Updated: 2019/08/23 22:20:45 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_initialize(int tab[10])
{
	int i;

	i = 0;
	while (i < 10)
		tab[i++] = 0;
}

void	print_tab_tenxten(int tab[10])
{
	int k;
	int line;

	line = 0;
	while (line < 10)
	{
		k = 0;
		while (tab[k] != line && k < 10)
		{
			write(1, "_", 1);
			write(1, " ", 1);
			k++;
		}
		if (tab[k] == line && k < 10)
		{
			write(1, "Q", 1);
			if (++k < 10)
				write(1, " ", 1);
		}
		while (k++ < 10)
		{
			write(1, "_", 1);
			if (k < 10)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		line++;
	}
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

void	ft_test_fill(int tab[10])
{
	tab[0] = 6;
	tab[1] = 3;
	tab[2] = 5;
	tab[3] = 1;
	tab[4] = 8;
	tab[5] = 4;
	tab[6] = 9;
	tab[7] = 0;
	tab[8] = 2;
	tab[9] = 7;
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
		if (where != j)
			if (tab[i] == tab[j])
				return (0);
		j++;
	}
	// Check Diagonales
	while (k < 10)
	{
		if (i - k >= 0)
			if ((tab[i - k] == i - k) ||
					(tab[i - k] == i + k))
				return (0);
		if (i + k < 10)
			if ((tab[i + k] == i - k) ||
					(tab[i + k] == i + k))
				return (0);
		k++;
	}
	return (1);
}
/*
int		ft_backtracking(int tab[10], int i, int j, int filling)
{



	return (0);
}*/

int		ft_ten_queens_puzzle(void)
{
	int		tab[10];

	ft_initialize(tab);

//	ft_test_fill(tab);

//	ft_backtracking(tab, 0, 0, 1);
//	print_tab_tenxten(tab);
//	write(1, "\n", 1);
	ft_print_result(tab);
	return (0);
}

int		main(void)
{
	printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

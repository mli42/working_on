/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:03:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/07 18:37:16 by mli              ###   ########.fr       */
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

int		ft_backtracking(int tab[10], int i, int filling, int x)
{
//	write(1, "P\n", 2);
	tab[i] = filling;
//	ft_print_result(tab);
	if (ft_check(tab, i) && (tab[i] <= 9))
	{
		ft_print_result(tab);
		x++;
		if (tab[i] < 9)
			return (ft_backtracking(tab, i, ++filling, x));
		else if ((tab[i] == 9) && (i < 9))
			return (ft_backtracking(tab, ++i, 0, x));
	}
	else if ((!(ft_check(tab, i))) && (tab[i] <= 9))
	{
		if (tab[i] < 9)
			return (ft_backtracking(tab, i, ++filling, x));
		else if ((tab[i] == 9) && (i > 0))
		{
			tab[i--] = 0;
			if (tab[i] < 9)
				return (ft_backtracking(tab, i, ++tab[i], x));
			return (ft_backtracking(tab, i, tab[i], x));
		}
	}
	return (x);
}

int		ft_ten_queens_puzzle(void)
{
	int		result;
	int		tab[10];

	ft_initialize(tab);

	ft_test_fill(tab);
	result = ft_backtracking(tab, 9, 6, 0);
	return (result);
}

int		main(void)
{
	printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

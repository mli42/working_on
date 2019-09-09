/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 03:03:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/09 23:57:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

	j = 0;
	// Check Ligne, No need Colonne
	while (j < i)
		if (tab[i] == tab[j++])
			return (0);
	// Check Diagonales
	j = 0;
	while (++j < 10)
		if (i - j >= 0)
			if ((tab[i - j] == tab[i] - j) || (tab[i - j] == tab[i] + j))
				return (0);
	return (1);
}

int		ft_backtracking(int tab[10], int i, int filling, int x)
{
	tab[i] = filling;
	while ((!(ft_check(tab, i))) && (tab[i] <= 9))
	{
		if ((tab[0] == 9) && (tab[1] == 9))
			break;
		while ((tab[i] == 9) && (i > 0))
			tab[i--] = 0;
		if (tab[i] < 9)
			(tab[i])++;
	}
	if (ft_check(tab, i) && (tab[i] <= 9))
	{
		if (i == 9)
		{
			ft_print_result(tab);
			tab[i--] = 0;
			if (tab[i] == 9)
				tab[i--] = 0;
			return (ft_backtracking(tab, i, ++(tab[i]), ++x));
		}
		if (i < 9)
			return (ft_backtracking(tab, ++i, 0, x));
	}
	return (x);
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int	tab[10];

	i = 0;
	while (i < 10)
		tab[i++] = 0;
	return (ft_backtracking(tab, 0, 0, 0));
}

int		main(void)
{
	printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

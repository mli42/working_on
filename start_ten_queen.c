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

void	ft_initialize(int tab[10][10])
{
	int i;
	int j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
			tab[i][j++] = 0;
		i++;
	}
}

void	print_tab_tenxten(int tab[10][10])
{
	int i;
	int j;
	int to_print;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			to_print = tab[i][j++] + 48;
			write(1, &to_print, 1);
			if (j != 10)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_result(int tab[10][10])
{
	int i;
	int j;
	int result;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (tab[i][j] == 1)
			{
				result = i + 48;
				write(1, &result, 1);
				if (j != 9)
					write(1, " ", 1);
				break;
			}
			i++;
		}
		j++;
	}
	write(1, "\n", 1);
}

/* void	ft_test_fill(int tab[10][10])
{
	tab[4][0] = 1;
	tab[2][1] = 1;
	tab[5][2] = 1;
	tab[7][3] = 1;
	tab[8][4] = 1;
	tab[1][5] = 1;
	tab[3][6] = 1;
	tab[6][7] = 1;
	tab[9][8] = 1;
	tab[0][9] = 1;
} */

int		ft_backtracking[10][10](int tab[10][10])
{

	return (tab);
}

int		ft_ten_queens_puzzle(void)
{
	int		tab[10][10];

	ft_initialize(tab);

/*	ft_test_fill(tab);
	write(1, "\n", 1); */
	print_tab_tenxten(tab);
	write(1, "\n", 1);
	ft_print_result(tab);
	return (0);
}

int		main(void)
{
	printf("Number of solutions: %d\n", ft_ten_queens_puzzle());
	return (0);
}

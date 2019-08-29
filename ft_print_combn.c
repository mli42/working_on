/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:40:54 by mli               #+#    #+#             */
/*   Updated: 2019/08/29 18:48:08 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *tab)
{
	int i;
	int to_print;

	i = 0;
	while (tab[i])
	{
		to_print = tab[i++] + 48;
		write(1, &to_print, 1);
	}
}

void	ft_print_combn(int n)
{
	int i;
	int k;
	int tab[n];

	i = 0;
	while (tab[i])
		tab[i++] = 0;
	i -= 1;

	k = 0;
	while (tab[k] <= (10 - n + k))
	{
		tab[i] = tab[i - 1] + 1;
		while (tab[i] < 9)
		{
			ft_print(tab);
			tab[i]++;
		}
		if (tab[i] == 9)
		{
			ft_print(tab);
			tab[i - 1]++;
			tab[i] = tab[i - 1] + 1;
		}
	}

}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_print_combn(argv[1][0]);
	return (0);
}

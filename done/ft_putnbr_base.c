/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:19:39 by mli               #+#    #+#             */
/*   Updated: 2019/09/12 01:59:33 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

int		base_check(char *base)
{
	int i;
	int j;

	// Base vide ou de taille 1
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	// Comporte uniquement chiffres et lettres
	i = 0;
	while (base[i])
	{
		if (!(base[i] >= '0' && base[i] <= '9') &&
				!(base[i] >= 'a' && base[i] <= 'z') &&
				!(base[i] >= 'A' && base[i] <= 'Z'))
			return (0);
		i++;
	}
	// Deux char identiques
	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int i;
	int base_len;
	int to_print;

	i = 0;
	to_print = nbr;
	base_len = base_check(base);
	//
	if (base_len)
		write(1, "Is a base\n", 10);
	else
		write(1, "Not a base\n", 11);
	//
	while (div >= base_len)
	{
		div /= base_len;
		i++;
	}

	while (a >= 0)
		write(1, &base[a--], 1);
	write(1, '\n', 1);

	printf("Length of the base: %d\n", base_len);
}

int		main(void)
{
	ft_putnbr_base(2, "0123456789ABCDEF");
	return (0);
}

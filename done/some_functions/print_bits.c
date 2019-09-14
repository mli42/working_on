/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 09:35:13 by mli               #+#    #+#             */
/*   Updated: 2019/08/13 10:05:29 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_bits(unsigned char a)
{
	int i;
	char result[8];

		/* Initialize the tab */
	i = 0;
	while (i < 8)
		result[i++] = '0';
		/* Algo */
	while (i-- > 0)
	{
		if ((a&1) == 1)
			result[i] = '1';
		a = a>>1;
	}
		/* Print the result */
	while (++i < 8)
		write(1, &result[i], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_bits((unsigned char)atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}

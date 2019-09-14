/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:08:04 by mli               #+#    #+#             */
/*   Updated: 2019/08/06 15:10:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_power_of_2(unsigned int n)
{
	unsigned int r;

	r = 1;
	while (r <= 2147483648)
	{
		if (r == n)
			return (1);
		r *= 2;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	if (is_power_of_2(atoi(argv[1])))
		printf("is a power of 2\n");
	else
		printf("not a power of 2\n");
	return (0);
}

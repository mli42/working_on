/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:45:27 by mli               #+#    #+#             */
/*   Updated: 2019/07/29 22:08:32 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		max(int *tab, unsigned int len)
{
	unsigned int i;
	int higher;

	i = 0;
	higher = 0;
	while (i < len)
	{
		if (higher < tab[i])
			higher = tab[i];
		i++;
	}
	return (higher);
}

int		main(void)
{
	int tab[] = {1, 4, 2, 0, 7, 3};
	unsigned int len = 7;

	printf("%d\n",max(tab, len));
	return (0);
}

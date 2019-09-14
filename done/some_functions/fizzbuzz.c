/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 10:10:36 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 10:27:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int a)
{
	if (a >= 0 && a <= 9)
	{
		a += 48;
		write(1, &a, 1);
	}
	else if (a >= 10)
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
}

void	ft_fizzbuzz(void)
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 != 0))
			write(1, "fizz\n", 5);
		else if ((i % 3 != 0) && (i % 5 == 0))
			write(1, "buzz\n", 5);
		else if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz\n", 9);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
}

int		main(void)
{
	ft_fizzbuzz();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:06:05 by exam              #+#    #+#             */
/*   Updated: 2019/07/26 12:19:11 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		not_seen(char *str, char to_test, int max)
{
	int i;

	i = -1;
	while (++i < max)
		if (str[i] == to_test)
			return (0);
	return (1);
}

int		is_in_b(char *str, char to_test)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == to_test)
			return (1);
	return (0);
}

void	ft_inter(char *a, char *b)
{
	int i;

	i = -1;
	while (a[++i])
		if (not_seen(a, a[i], i) && is_in_b(b, a[i]))
			write(1, &a[i], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

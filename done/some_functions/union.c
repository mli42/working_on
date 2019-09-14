/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:08:56 by mli               #+#    #+#             */
/*   Updated: 2019/07/29 22:38:17 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		lens1(char *s1)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

int		not_seen(char *str, char to_test, int max)
{
	int i;

	i = -1;
	while (++i < max)
		if (str[i] == to_test)
			return (0);
	return (1);
}

void	ft_union(char *s1, char *s2)
{
	int i;

	i = -1;
	while (s1[++i])
		if (not_seen(s1, s1[i], i))
			write(1, &s1[i], 1);
	i = -1;
	while (s2[++i])
		if (not_seen(s1, s2[i], lens1(s1)) && not_seen(s2, s2[i], i))
			write(1, &s2[i], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

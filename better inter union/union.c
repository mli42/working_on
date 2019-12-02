/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:36:40 by mli               #+#    #+#             */
/*   Updated: 2019/12/02 16:42:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		seen_before(char *s, int max, char c)
{
	int i = -1;

	while (s[++i] && i < max)
		if (s[i] == c)
			return (1);
	return (0);
}

void	ft_union(char *a, char *b)
{
	int i = -1;
	int j = -1;

	while (a[++i])
		if (!seen_before(a, i, a[i]))
			write(1, &a[i], 1);
	while (b[++j])
		if (!seen_before(a, i, b[j]) && !seen_before(b, j, b[j]))
			write(1, &b[j], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

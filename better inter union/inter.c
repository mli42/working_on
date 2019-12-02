/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:16:55 by mli               #+#    #+#             */
/*   Updated: 2019/12/02 16:52:16 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_in_s(char *s, int max, char c)
{
	int i = 0;

	while (s[i] && i < max)
		if (c == s[i++])
			return (1);
	return (0);
}

void	ft_inter(char *s1, char *s2)
{
	int i = -1;
	int j = 0;

	while (s2[j])
		j++;
	while (s1[++i])
		if (!is_in_s(s1, i, s1[i]) && is_in_s(s2, j, s1[i]))
			write(1, &s1[i], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}

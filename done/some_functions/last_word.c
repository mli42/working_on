/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:35:43 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 18:51:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_last_word(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	i -= 1;
	while (argv[i] == ' ' || argv[i] == '\t')
		i--;
	if (argv[i] == '\0')
		return (0);
	while (argv[i] != ' ' && argv[i] != '\t' && argv[i] != '\0')
		i--;
	i += 1;
	while (argv[i] != ' ' && argv[i] != '\t' && argv[i] != '\0')
		write(1, &argv[i++], 1);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}

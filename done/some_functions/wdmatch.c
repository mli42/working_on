/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:54:35 by mli               #+#    #+#             */
/*   Updated: 2019/08/14 22:33:00 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_first_param(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int		ft_wdmatch(char *to_print, char *to_test)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (to_print[i])
	{
		if (to_test[j] == '\0')
			return (0);
		else if (to_print[i] == to_test[j])
			i++;
		j++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		if (ft_wdmatch(argv[1], argv[2]))
			print_first_param(argv[1]);
	write(1, "\n", 1);
	return (0);
}

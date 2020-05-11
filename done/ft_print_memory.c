/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 21:59:36 by mli               #+#    #+#             */
/*   Updated: 2020/05/11 23:35:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printable(const unsigned char *str, int left)
{
	int i;

	i = -1;
	while (++i < 16 && i < left)
	{
		if (ft_isprint(str[i]))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
	}
}

void	ft_print_hex(const unsigned char *str, unsigned int left)
{
	unsigned int	i;
	int				written;
	const int		max = 8 * 4 + 8;

	i = 0;
	written = 0;
	while (written < max && i < left)
	{
		written += 2;
		ft_printf("%02x", str[i++]);
		if (i % 2 == 0 && written++)
			write(1, " ", 1);
	}
	while (written++ < max)
		write(1, " ", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		left;
	const unsigned char	*str = addr;

	i = 0;
	while (i < size)
	{
		left = (size - i);
		ft_printf("%015x: ", &str[i]);
		ft_print_hex(&str[i], left);
		ft_printable(&str[i], left);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

int		main(int argc, char **argv)
{
	(void)argc; (void)argv;
	char *str = "Bonjour les aminches\t\n\tc  est fou tout ce qu on peut faire avec\x9\n\x9print_memory..\n\x09lol.lol\n \0";
	int len = ft_strlen(str) + 1;

	if (ft_print_memory(str, len) != str)
		ft_printf("Returned value error\n");
}

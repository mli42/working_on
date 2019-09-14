/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:33:36 by mli               #+#    #+#             */
/*   Updated: 2019/09/14 20:14:02 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <unistd.h>
#include <stdio.h>

int		ft_atoi_base(char *str, char *base, int base_len);
void    ft_putnbr(int nbr, char *base, long int base_len, char *result);

int		base_check(char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t' ||
				base[i] == '\n' || base[i] == '\v' || base[i] == '\f' ||
				base[i] == '\r' || base[i] == ' ')
			return (0);
		i++;
	}
	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (i + 1);
}

int		result_size(long int nb, long int base_len)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb *= (-1);
		i++;
	}
	while (nb >= base_len)
	{
		nb /= base_len;
		i++;
	}
	return (i + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			base_len_from;
	int			base_len_to;
	char		*result;
	int			size;

	base_len_from = base_check(base_from);
	base_len_to = base_check(base_to);
	if (!(base_len_from) || !(base_len_to))
		return (NULL);
	nb = (long int)ft_atoi_base(nbr, base_from, base_len_from);
	size = result_size(nb, base_len_to);
	if (!(result = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_putnbr(nb, base_to, base_len_to, result);
	result[size - 1] = '\0';
	free(result);
	return(result);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s\n", ft_convert_base(argv[1], "0123456789", "0123456789ABCDEF"));
	else if (argc == 3)
		printf("%s\n", ft_convert_base(argv[1], argv[2], "0123456789ABCDEF"));
	else if (argc == 4)
		printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}

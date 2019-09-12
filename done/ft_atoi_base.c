/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:46:35 by mli               #+#    #+#             */
/*   Updated: 2019/09/12 22:01:18 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	base_check(char *str, char *base)
{
	int i;
	int j;

	if (base[0] == '\0' || base[1] == '\0' || str[0] == '\0')
		return (0);
	// Comporte uniquement chiffres et lettres
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t' ||
				base[i] == '\n' || base[i] == '\v' || base[i] == '\f' ||
				base[i] == '\r' || base[i] == ' ')
			return (0);
		i++;
	}
	// Deux char identiques
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
int in_base(char to_test, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == to_test)
			return (i);
	return (0);
}

int	power(int x, int puissance)
{
	int i;
	int r;

	i = 0;
	r = 1;
	while (i++ < puissance)
		r *= x;
	return (r);
}

int	ft_convert(char *str, char *base, int base_len)
{
	int i;
	int signe;
	int result;
	int str_max;

	i = 0;
	signe = 1;
	result = 0;

	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe *= (-1);
	str_max = i;
	while (in_base(str[str_max], base) || (base[0] == str[str_max]))
		str_max++;
	str_max--;
	while ((in_base(str[i], base) || base[0] == str[i]) && (i <= str_max))
	{
		result += (in_base(str[i], base) * power(base_len, (str_max - i)));
		i++;
	}
	return (result * signe);
}

int	ft_atoi_base(char *str, char *base)
{
	int result;
	int base_len;

	result = 0;
	base_len = base_check(str, base);
	if (base_len)
		result = ft_convert(str, base, base_len);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%d\n" ,ft_atoi_base(argv[1], "0123456789ABCDEF"));
	return (0);
}

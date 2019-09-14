/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 23:33:41 by mli               #+#    #+#             */
/*   Updated: 2019/09/14 20:11:54 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		in_base(char to_test, char *base)
{
	int i;

	i = -1;
	while (base[++i])
		if (base[i] == to_test)
			return (i);
	return (0);
}

int		power(int x, int puissance)
{
	int i;
	int r;

	i = 0;
	r = 1;
	while (i++ < puissance)
		r *= x;
	return (r);
}

int		ft_atoi_base(char *str, char *base, int base_len)
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

void    ft_convert(long int nbr, char *base, long int base_len, char *r, int i)
{
	int begin;
	int swap;

	begin = i;
	while (nbr >= base_len)
	{
		r[i++] = base[nbr % base_len];
		nbr /= base_len;
	}
	r[i] = base[nbr % base_len];
	while (begin < i)
	{
		swap = r[begin];
		r[begin] = r[i];
		r[i--] = swap;
		begin++;
	}
}

void    ft_putnbr(int nbr, char *base, long int base_len, char *result)
{
    long int nb;

    nb = (long int)nbr;
	if (nbr < 0)
	{
		result[0] = '-';
		nb *= (-1);
		ft_convert(nb, base, base_len, result, 1);
	}
	else
		ft_convert(nb, base, base_len, result, 0);
}

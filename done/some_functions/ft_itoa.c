/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 18:41:53 by mli               #+#    #+#             */
/*   Updated: 2019/07/31 02:39:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		nbr_len(int nbr)
{
	int len;

	len = 0;
	while (nbr /= 10)
		len++;
	return (len);
}

char	*ft_itoa(int nbr)
{
	int len;
	char *result;
	int signe;

	len = 1;
	signe = 1;
	if (nbr < 0)
	{
		signe = -1;
		len++;
		nbr *= (-1);
		if (nbr == -2147483648)
			nbr = 2147483647;
	}
	len += nbr_len(nbr);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len] = (nbr % 10) + 48;
		if (nbr == 2147483647 && signe == -1)
			result[len] = '8';
		printf("Case remplit: %d || ", len);
		printf("With what filled: %c\n", result[len]);
		len--;
		nbr /= 10;
		if (signe == (-1) && len == 0)
			result[len--] = '-';
	}
	printf("Result: %s\n", result);
	return (result);
}

int		main(void)
{
	int n;

	n = -2147483648;
	ft_itoa(n);
	return (0);
}

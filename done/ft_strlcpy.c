/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:51:52 by mli               #+#    #+#             */
/*   Updated: 2019/09/22 21:21:40 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (((size - 1) > i) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

int				main(void)
{
	char dest[] = "something not important";
	char src[] = "copied but greater than the dest";
	printf("%d with mine\n", ft_strlcpy(dest, src, strlen(dest)));
	printf("%s\n", dest);
	printf("%d with the real\n", (int)strlcpy(dest, src, strlen(dest)));
	printf("%s\n", dest);
	printf("%d the len of src\n", (int)strlen(src));
	return (0);
}

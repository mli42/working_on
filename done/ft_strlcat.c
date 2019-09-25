/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:55:15 by mli               #+#    #+#             */
/*   Updated: 2019/09/25 16:42:17 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = -1;
	while (dest[i] && (i < size))
		i++;
	while (src[++j])
		if (i + j < size - 1)
			dest[i + j] = src[j];
	if (i + j < size)
		dest[i + j] = '\0';
	printf("dest_len: %d\nsrc_len: %d\nsize: %d\n\n", i, j, size);
	return (i + j);
}

int			main(void)
{
	char dest[30] = "12345";
	char dest2[30] = "12345";
	char src[] = "6789";
	unsigned int size = 6;

	printf("%d strlen(src) + strlen(dest)\n", (int)strlen(src) + (int)strlen(dest));
	printf("%d strlen(src) + size\n\n", (int)strlen(src) + size);

	printf("%d with mine\n", ft_strlcat(dest, src, size));
	printf("%s\n", dest);
	printf("%d with the real\n", (int)strlcat(dest2, src, size));
	printf("%s\n", dest2);
	return (0);
}

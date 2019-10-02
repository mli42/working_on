/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:56:40 by mli               #+#    #+#             */
/*   Updated: 2019/10/02 16:35:25 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

int		ft_first_line(int fd, char *content, int size, char fills[4])
{
	int i;

	i = 0;
	while (*content >= '0' && *content <= '9')
	{
		size = (size * 10) + *content - '0';
		read(fd, content, 1);
	}
	while (*content != '\n')
	{
		fills[i++] = *content;
		read(fd, content, 1);
	}
	fills[i] = *content;
	return (size);
}

int		ft_map_len(int fd, char content, char fills[4])
{
	int len1;
	int len2;

	len1 = 0;
	while (read(fd, &content, 1) && content != '\n')
	{
		if (content != fills[0] && content != fills[1] && content != '\n')
			return (0);
		len1++;
	}
	len2 = 0;
	while (read(fd, &content, 1))
	{
		if (content != fills[0] && content != fills[1] && content != '\n')
			return (0);
		if (content == '\n')
		{
			if (len1 != len2)
				return (0);
			len2 = -1;
		}
		len2++;
	}
	return (len1);
}

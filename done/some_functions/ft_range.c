/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 19:30:16 by exam              #+#    #+#             */
/*   Updated: 2019/07/19 20:39:19 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int i;
	int range;
	int *ptr;

	i = 0;
	ptr = 0;
	range = start - end;
	if (range < 0)
		range *= -1;
	if (start == 0 && end == 0)
	{
		ptr = (int *)malloc(sizeof(ptr) * 1);
		ptr[0] = 0;
		return (ptr);
	}
	if (!(ptr = (int *)malloc(sizeof(ptr) * range)))
		return (0);
	if (start >= end)
		while (start >= end)
			ptr[i++] = start--;
	else if (end >= start)
		while (end >= start)
			ptr[i++] = start++;
	return (ptr);
}

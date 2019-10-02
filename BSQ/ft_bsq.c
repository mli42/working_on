/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:27:56 by mli               #+#    #+#             */
/*   Updated: 2019/10/02 23:23:48 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_includes.h"

void	ft_ijmax(int ijmax[3], int pos[2], int max)
{
	ijmax[0] = pos[0];
	ijmax[1] = pos[1];
	ijmax[2] = max;
}

void	ft_initialize(int *max, int pos[2], int ijmax[3])
{
	pos[0] = 0;
	pos[1] = 0;
	*max = 1;
	ft_ijmax(ijmax, pos, *max);
}


void	ft_bsq(char **map, int size, int len, char fills[4])
{
	int		max;
	int		pos[2];
	int		ijmax[3];

	ft_initialize(&max, pos, ijmax);
	while (pos[0] < size -1)
	{
		while (map[pos[0]][pos[1]] != fills[0])
		{
			while (map[pos[0]][pos[1]] == fills[1] && pos[1] < len)
				pos[1]++;
			if (pos[1] == len)
			{
				pos[0]++;
				pos[1] = 0;
			}
		}
		max = 1;
//		while (ft_can_place(map, pos, max, fills))
			max++;
		if (max > ijmax[2])
			ft_ijmax(ijmax, pos, max);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 22:27:56 by mli               #+#    #+#             */
/*   Updated: 2019/10/03 20:12:12 by mli              ###   ########.fr       */
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
	*max = 0;
	ft_ijmax(ijmax, pos, *max);
}

void	ft_search_next_position(char **map, char fills[4], int *i, int *j)
{
	while (map[*i][*j] != fills[0])
	{
		while (map[*i][*j] != fills[0] && map[*i][*j])
			(*j)++;
		if (map[*i][*j] == '\0')
		{
			(*i)++;
			*j = 0;
		}
	}
}

int		ft_can_place(char **map, char fills[4], int pos[2], int max)
{
	int i;
	int j;
	int k;

	k = 0;
	i = pos[0];
	j = pos[1];
	if (map[i + max] == NULL || map[i + max][j] == fills[1])
		return (0);
	if (!map[i][j + max] || map[i][j + max] == fills[1])
		return (-max);
	while (k <= max)
	{
		if (map[i + k][j + max] == fills[1])
			return (-max);
		if (map[i + max][j + k] == fills[1])
			return (-k);
		k++;
	}
	return (1);
}

void	ft_fill_map_resolved(char **map, char fills[4], int ijmax[3])
{
	int k;
	int l;

	k = -1;
	while (++k <= ijmax[2])
	{
		l = -1;
		while (++l <= ijmax[2])
			map[ijmax[0] + k][ijmax[1] + l] = fills[2];
	}
}

void	ft_bsq(char **map, char fills[4])
{
	int		max;
	int		error;
	int		pos[2];
	int		ijmax[3];

	ft_initialize(&max, pos, ijmax);
	while (map[pos[0]] != NULL)
	{
		if (map[pos[0]][pos[1]] != fills[0])
			ft_search_next_position(map, fills, &(pos[0]), &(pos[1]));
		max = 0;
		while ((error = ft_can_place(map, fills, pos, max)) > 0)
			max++;
		if (--max > ijmax[2])
			ft_ijmax(ijmax, pos, max);
		if (error < 0)
			pos[1] -= error;
		pos[1]++;
		if (map[pos[0]][pos[1]] == '\0')
		{
			pos[0]++;
			pos[1] = 0;
		}
	}
	ft_fill_map_resolved(map, fills, ijmax);
}

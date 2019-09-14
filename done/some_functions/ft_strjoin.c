/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 11:33:46 by mli               #+#    #+#             */
/*   Updated: 2019/07/22 17:12:55 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		len(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		strs_len;
	int		sep_len;

	i = 0;
	strs_len = 0;
	sep_len = 0;
	while (sep[sep_len])
		sep_len++;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			strs_len++;
		i++;
	}
	return (sep_len * (size - 1) + strs_len + 1);
}

char	*ft_check_size(char *result)
{
	if (!(result = (char *)malloc(sizeof(char))))
		return (0);
	else
	{
		result[0] = '\0';
		return (result);
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	k = 0;
	if (size == 0)
		return (ft_check_size(NULL));
	if (!(result = (char *)malloc(sizeof(char) * len(size, strs, sep))))
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		j = 0;
		if (i++ < size - 1)
			while (sep[j])
				result[k++] = sep[j++];
	}
	result[k] = '\0';
	return (result);
}

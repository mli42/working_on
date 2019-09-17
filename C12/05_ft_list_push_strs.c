/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_ft_list_push_strs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:34:30 by mli               #+#    #+#             */
/*   Updated: 2019/09/17 23:46:14 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int i;
	t_list *after;
	t_list *before;

	i = 0;
	after = ft_create_elem(strs[i++]);
	while (i < size)
	{
		before = ft_create_elem(strs[i]);
		before->next = after;
		after = before;
		i++;
	}
	return (after);
}

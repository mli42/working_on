/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ft_list_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:58:28 by mli               #+#    #+#             */
/*   Updated: 2019/09/19 15:35:33 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_reverse(t_list **begin_list)
{
	int		size;
	t_list	*before;
	t_list	*after;

	size = ft_list_size(*begin_list);

	before = begin_list;
	begin_list = begin_list->next;
	after = begin_list->next;
	before->next = NULL;
	while (after != NULL)
	{
		before = begin_list;
		begin_list = after;
		after = after->next;
		begin_list->next = before;
	}
	after->next = begin_list;
}

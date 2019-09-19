/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_list_remove_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:59:47 by mli               #+#    #+#             */
/*   Updated: 2019/09/19 23:36:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list *before;
	t_list *current;
	t_list *after;

	before = NULL;
	current = *begin_list;
	after = current->next;
	while (current != NULL)
	{
		if (!((*cmp)(current->data, data_ref)) && before && after)
		{
			(*free_fct)(current->data);
			before->next = after;
			free(current);
			current = after;
			after = current->next;
		}
		else if (!((*cmp)(current->data, data_ref)) && !before && after)
		{
			(*free_fct)(current->data);
			free(current);
			before->next = after;
		}
		else if (!((*cmp)(current->data, data_ref)) && before && !after)
		{
		
		}
		else
		{
			before = current;
			current = after;
			after = current->next;
		}
		if (*begin_list = current)
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_ft_list_remove_if.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:59:47 by mli               #+#    #+#             */
/*   Updated: 2019/09/21 23:54:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *))
{
	t_list	*current;
	t_list	*to_delete;

	while (!((*cmp)((*begin_list)->data, data_ref)) && *begin_list)
	{
		to_delete = *begin_list;
		*begin_list = to_delete->next;
		(*free_fct)(to_delete->data);
		free(to_delete);
	}
	current = *begin_list;
	while (current != NULL)
	{
		if (!((*cmp)(current->next->data, data_ref)) && current->next)
		{
			to_delete = current->next;
			current->next = current->next->next;
			(*free_fct)(to_delete->data);
			free(to_delete);
		}
		while ((*cmp)(current->data, data_ref) && current)
			current = current->next;
	}
}

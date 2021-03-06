/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_ft_list_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:58:28 by mli               #+#    #+#             */
/*   Updated: 2019/09/19 22:33:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*before;
	t_list	*current;
	t_list	*after;

	current = *begin_list;
	before = NULL;
	after = current->next;
	while (after != NULL)
	{
		current->next = before;
		before = current;
		current = after;
		after = current->next;
	}
	current->next = before;
	*begin_list = current;
}

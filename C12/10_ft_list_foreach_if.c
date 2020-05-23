/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_ft_list_foreach_if.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:40:27 by mli               #+#    #+#             */
/*   Updated: 2020/05/22 23:26:23 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!((*cmp)(begin_list->data, data_ref)))
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

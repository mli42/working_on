/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_ft_list_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:52:07 by mli               #+#    #+#             */
/*   Updated: 2019/09/19 22:58:51 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while(begin_list)
	{
		if (!((*cmp)(begin_list->data, data_ref)))
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}

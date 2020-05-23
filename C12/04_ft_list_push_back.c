/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_ft_list_push_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:13:48 by mli               #+#    #+#             */
/*   Updated: 2020/05/22 23:25:44 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_last;

	new_last = ft_create_elem(data);
	if (!(*begin_list))
		*begin_list = new_last;
	else
	{
		while ((*begin_list)->next != NULL)
			*begin_list = (*begin_list)->next;
		(*begin_list)->next = new_last;
	}
}

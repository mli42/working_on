/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_ft_list_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:15:32 by mli               #+#    #+#             */
/*   Updated: 2019/09/22 16:20:47 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (*begin_list1)
		ft_list_merge(&((*begin_list1)->next), begin_list2);
	else
		*begin_list1 = begin_list2;
}

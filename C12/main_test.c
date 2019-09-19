/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:10:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/19 22:32:20 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_reverse(t_list **begin_list);

void	ft_print_list(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		printf("%s", begin_list->data);
			if (begin_list->next)
				printf(" || ");
		begin_list = begin_list->next;
	}
	printf("\n");
}

int		main(void)
{
	t_list	*list;

	char *strs[] = {"Hello", "Moon", "Sun", "Hey", "Wouah"};
	list = ft_list_push_strs(5, strs);
	ft_print_list(list);
	ft_list_reverse(&list);
	ft_print_list(list);
	return (0);
}

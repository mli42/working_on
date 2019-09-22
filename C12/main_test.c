/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:10:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/22 13:16:30 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_reverse(t_list **begin_list);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *));

int		compare(char *s1, char *s2)
{
	if (s1 == s2)
		return (0);
	return (1);
}

void	free_function(void *data)
{
	printf("Deleted: %s\n", data);
}

void	ft_print_list(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		printf("%s", begin_list->data);
			if (begin_list->next)
				printf(" -> ");
		begin_list = begin_list->next;
	}
	printf("\n");
}

int		main(void)
{
	t_list	*list;
	char *strs[] = {"1", "2", "3", "4", "R"};
//	00 create elem + 05 push strs
	list = ft_list_push_strs(5, strs);
	ft_print_list(list);
//	08 List Reverse
	ft_list_reverse(&list);
	ft_print_list(list);
//	12 Remove if
	printf("\n");
	int (*cmp)() = &compare;
	void (*free_fct)(void *) = &free_function;
	ft_list_remove_if(&list, "R", cmp, free_fct);
	printf("\nList Content:\n");
	ft_print_list(list);


	return (0);
}

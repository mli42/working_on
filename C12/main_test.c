/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:10:40 by mli               #+#    #+#             */
/*   Updated: 2020/05/22 23:46:06 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);
void	ft_list_reverse(t_list **begin_list);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
		void (*free_fct)(void *));
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

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

void	ft_test(t_list **lst)
{
	printf("I'M TESTING\n");
	*lst = (*lst)->next->next->next;
	ft_print_list(*lst);
}

void	ft_test2(t_list *lst)
{
	ft_test(&lst);
	printf("\nTEST 2:\n");
	ft_print_list(lst);
}

int		main(void)
{
	t_list	*list;
	t_list	*list2;
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
//	13 List Merge
	char *strs2[] = {"5", "6", "7", "8", "9"};
	list2 = ft_list_push_strs(5, strs2);
	ft_list_reverse(&list2);
	printf("\nMerging these lists:\n");
	ft_print_list(list);
	ft_print_list(list2);
	//list = NULL;
	ft_list_merge(&list, list2);
	printf("Gives: ");
	ft_print_list(list);
	printf("\n");

	t_list **alst = &list;
	t_list *test = list->next->next->next->next;
	test = list;
//	list = list->next;
	ft_test2(test);

	printf("\nTEST:\n");
	ft_print_list(test);
	printf("\nLIST:\n");
	ft_print_list(list);
	printf("\nORIGINAL:\n");
	ft_print_list(*alst);
	return (0);
}

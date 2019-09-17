/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:10:40 by mli               #+#    #+#             */
/*   Updated: 2019/09/17 23:21:58 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs);

void	ft_print_list(t_list *begin_list)
{
	while (begin_list != NULL)
	{
		printf("%s\n", begin_list->data);
		begin_list = begin_list->next;
	}
}

int		main(void)
{
	char *strs[] = {"Hello", "Moon", "Sun", "Hey", "Wouah"};
	ft_print_list(ft_list_push_strs(5, strs));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:28:01 by mli               #+#    #+#             */
/*   Updated: 2020/05/01 19:00:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*create_a_tree(void)
{
	t_btree *head;

	head = btree_create_node("A");

	head->left = btree_create_node("B");
	head->left->left = btree_create_node("C");
	head->left->right = btree_create_node("D");

	head->right = btree_create_node("E");
	head->right->left = btree_create_node("F");
	head->right->right = btree_create_node("G");

	return (head);
}

void	ft_putstr(void *str)
{
	printf("%s ", (char *)str);
}

void	ft_print_mode(char *str, t_btree *node, void (*f)(t_btree *, void (*)()))
{
	printf("Print %s : ", str);
	f(node, ft_putstr);
	printf("\n");
}

int		main(void)
{
	t_btree *node = create_a_tree();

	ft_print_mode("prefix", node, btree_apply_prefix);
	ft_print_mode("infix", node, btree_apply_infix);
	ft_print_mode("suffix", node, btree_apply_suffix);

	return (0);
}

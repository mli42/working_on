/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:28:01 by mli               #+#    #+#             */
/*   Updated: 2020/05/02 00:22:27 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*create_a_tree(void)
{
	t_btree *head;

	head = btree_create_node("5");

	head->left = btree_create_node("3");
	head->left->left = btree_create_node("1");
	head->left->right = btree_create_node("4");

	head->right = btree_create_node("7");
	head->right->left = btree_create_node("6");
	head->right->right = btree_create_node("9");

	return (head);
}

void	ft_putstr(void *str)
{
	printf("%s ", (char *)str);
}

int		ft_diff(void *a, void *b)
{
	char *x = (char *)a;
	char *y = (char *)b;

	return (x[0] - y[0]);
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

//	ft_print_mode("prefix", node, btree_apply_prefix);
	ft_print_mode("infix", node, btree_apply_infix);
//	ft_print_mode("suffix", node, btree_apply_suffix);

	printf("\nBtree insert '2' and '8'\n");
	btree_insert_data(&node, "2", ft_diff);
	btree_insert_data(&node, "8", ft_diff);
	ft_print_mode("infix", node, btree_apply_infix);
	printf("\nBtree insert '5'\n");
	btree_insert_data(&node, "5", ft_diff);
	ft_print_mode("infix", node, btree_apply_infix);

	return (0);
}

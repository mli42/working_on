/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:28:01 by mli               #+#    #+#             */
/*   Updated: 2020/05/02 14:51:26 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*create_a_tree(void)
{
	t_btree *head;

	head = btree_new("5");

	head->left = btree_new("3");
	head->left->left = btree_new("1");
	head->left->right = btree_new("4");

	head->right = btree_new("7");
	head->right->left = btree_new("6");
	head->right->right = btree_new("9");

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

	printf("\tCompare [%s] | [%s]\n", x, y);
	if (!x || !y)
		return (1);
	else if (x == y)
		return (0);
	return (x[0] - y[0]);
}

void	ft_insert(t_btree **atree, void *item)
{
	t_btree *node = btree_new(item);

	printf("Btree insert '%s'\n", (char *)item);
	btree_add(atree, node, ft_diff);
}

void	ft_print_mode(char *str, t_btree *node, void (*f)(t_btree *, void (*)()))
{
	printf("Print tree in mode %s : ", str);
	f(node, ft_putstr);
	printf("\n");
}

void	ft_find(t_btree *root, void *data_ref)
{
	printf("Search [%s]\n", (char *)data_ref);
	char *res = (char *)btree_find(root, data_ref, ft_diff);
	printf("Found : [%s] | Search [%s]\n", res, (char *)data_ref);
}

int		main(void)
{
	t_btree *node = create_a_tree();

//	ft_print_mode("prefix", node, btree_apply_prefix);
	ft_print_mode("infix", node, btree_apply_infix);
//	ft_print_mode("suffix", node, btree_apply_suffix);

	ft_insert(&node, "2");
	ft_insert(&node, "8");
	ft_print_mode("infix", node, btree_apply_infix);
	ft_insert(&node, "5");
	ft_print_mode("infix", node, btree_apply_infix);

	ft_find(node, "3");
	ft_find(node, NULL);

	return (0);
}

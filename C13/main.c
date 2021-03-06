/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:28:01 by mli               #+#    #+#             */
/*   Updated: 2020/05/02 23:42:59 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*create_a_tree(void)
{
	t_btree *head = NULL;

	head = btree_new("5");

	head->left = btree_new("3");
	head->left->left = btree_new("1");
	head->left->right = btree_new("4");

	head->right = btree_new("7");
	head->right->left = btree_new("6");
	head->right->right = btree_new("9");

	return (head);
}

void	ft_print_item(void *str)
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
	f(node, ft_print_item);
	printf("\n");
}

void	ft_find(t_btree *root, void *data_ref)
{
	printf("Search [%s]\n", (char *)data_ref);
	char *res = (char *)btree_find(root, data_ref, ft_diff);
	printf("Found : [%s] | Search [%s]\n", res, (char *)data_ref);
}

int		ft_bfs(void *item, int curr_lv, int is_first)
{
	static int prev = 0, curr = 0;

	curr = curr_lv;
	if (prev != curr)
	{
		prev = curr;
		printf("\n");
	}
	printf("'%s' [lv:%d] [first?:%d]\n", (char *)item, curr_lv, is_first);

	return (1);
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

	printf("Btree size [%d]\n", btree_depth(node));

	btree_apply_bfs(node, ft_bfs);
	btree_apply_bfs(NULL, ft_bfs);

	return (0);
}

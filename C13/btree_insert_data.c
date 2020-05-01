/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:42:20 by mli               #+#    #+#             */
/*   Updated: 2020/05/02 00:15:05 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree *parent;
	t_btree *node;
	t_btree *new;
	int		side;

	if (!root || !(new = btree_create_node(item)))
		return ;
	if (!(node = *root))
		*root = new;
	while (node)
	{
		parent = node;
		if ((side = cmpf(node->item, item)) < 0)
			node = node->right;
		else if ((side = cmpf(node->item, item)) >= 0)
			node = node->left;
	}
	if (side >= 0)
		parent->left = new;
	else
		parent->right = new;
}

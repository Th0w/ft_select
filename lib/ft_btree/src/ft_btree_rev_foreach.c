/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rev_foreach.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:06:37 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/27 17:13:11 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void				btree_foreach_rev(t_btree *root, void (*act)())
{
	if (root == NULL)
		return ;
	btree_foreach_rev(root->right, act);
	act(root->content);
	btree_foreach_rev(root->left, act);
}

void				btree_foreach_rev_if(t_btree *root, void (*act)(),
										int (*assert)())
{
	if (root == NULL)
		return ;
	btree_foreach_rev_if(root->right, act, assert);
	if (assert(root))
		act(root->content);
	btree_foreach_rev_if(root->left, act, assert);
}

void				btree_foreach_rev_data(t_btree *root, void (*act)(),
											void *data)
{
	if (root == NULL)
		return ;
	btree_foreach_rev_data(root->right, act, data);
	act(root->content, data);
	btree_foreach_rev_data(root->left, act, data);
}

void				btree_foreach_rev_if_data(t_btree *root, void (*act)(),
										int (*assert)(), void *data)
{
	if (root == NULL)
		return ;
	btree_foreach_rev_if_data(root->right, act, assert, data);
	if (assert(root))
		act(root->content, data);
	btree_foreach_rev_if_data(root->left, act, assert, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:09:55 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/20 17:49:56 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void				btree_foreach(t_btree *root, void (*act)())
{
	if (root == NULL)
		return ;
	btree_foreach(root->left, act);
	act(root->content);
	btree_foreach(root->right, act);
}

void				btree_foreach_if(t_btree *root, void (*act)(),
										int (*assert)())
{
	if (root == NULL)
		return ;
	btree_foreach_if(root->left, act, assert);
	if (assert(root))
		act(root->content);
	btree_foreach_if(root->right, act, assert);
}

void				btree_foreach_data(t_btree *root, void (*act)(), void *data)
{
	if (root == NULL)
		return ;
	btree_foreach_data(root->left, act, data);
	act(root->content, data);
	btree_foreach_data(root->right, act, data);
}

void				btree_foreach_if_data(t_btree *root, void (*act)(),
										int (*assert)(), void *data)
{
	if (root == NULL)
		return ;
	btree_foreach_if_data(root->left, act, assert, data);
	if (assert(root))
		act(root->content, data);
	btree_foreach_if_data(root->right, act, assert, data);
}

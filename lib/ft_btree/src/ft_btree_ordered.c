/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:24:28 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/19 14:24:57 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void				btree_preorder(t_btree *root, void (*act)())
{
	if (root == NULL)
		return ;
	act(root);
	btree_foreach(root->left, act);
	btree_foreach(root->right, act);
}

void				btree_postorder(t_btree *root, void (*act)())
{
	if (root == NULL)
		return ;
	btree_foreach(root->left, act);
	btree_foreach(root->right, act);
	act(root);
}

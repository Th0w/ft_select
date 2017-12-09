/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:36:17 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:36:19 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void					btree_rotate_left(btree **root)
{
	btree				*tmp;

	tmp = (*root)->left;
	(*root)->left = (*root)->left->right;
	tmp->right = *root;
	*root = tmp;
}

void					btree_rotate_right(btree **root)
{
	btree				*tmp;

	tmp = (*root)->right;
	(*root)->right = (*root)->right->left;
	tmp->left = *root;
	*root = tmp;
}

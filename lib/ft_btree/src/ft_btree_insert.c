/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:36:32 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/20 15:31:16 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree						*btree_insert(t_btree *root, t_btree *elem,
											int (*cmp)())
{
	if (root == NULL)
		return (elem);
	if (cmp(elem, root) > 0)
		root->right = btree_insert(root->right, elem, cmp);
	else
		root->left = btree_insert(root->left, elem, cmp);
	return (root);
}

static t_btree				*insert(t_btree *root, void *content, int (*cmp)())
{
	int						left;

	left = ((*cmp)(content, root->content)) < 0;
	if (left != 0)
	{
		if (root->left == NULL)
			return (root->left = btree_create(content));
		else
			return (insert(root->left, content, cmp));
	}
	else
	{
		if (root->right == NULL)
			return (root->right = btree_create(content));
		else
			return (insert(root->right, content, cmp));
	}
}

t_btree						*btree_insert_content(t_btree **root, void *content,
													int (*cmp)())
{
	if (root == NULL)
		return (NULL);
	if (*root == NULL)
		return (*root = btree_create(content));
	else
		return (insert(*root, content, cmp));
}

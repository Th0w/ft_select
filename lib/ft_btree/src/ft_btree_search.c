/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:16:34 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:36:39 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree			*btree_search(t_btree *node, void *content, int (*cmp)())
{
	void		*lhs;
	void		*rhs;

	if (node == NULL)
		return (NULL);
	if (cmp(node->content, content) == 0)
		return (node);
	lhs = btree_search(node->left, content, cmp);
	rhs = btree_search(node->right, content, cmp);
	if (lhs != NULL)
		return (lhs);
	return (rhs);
}

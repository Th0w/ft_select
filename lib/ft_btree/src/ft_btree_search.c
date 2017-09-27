/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:16:34 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/19 14:19:26 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree			*btree_search(t_btree *node, void *content, int (*cmp)())
{
	void		*result;

	if (node == NULL)
		return (NULL);
	if (cmp(node->content, content) == 0)
		return (node);
	if ((result = btree_search(node->left, content, cmp)) != NULL)
		return (result);
	if ((result = btree_search(node->right, content, cmp)) != NULL)
		return (result);
	return (NULL);
}

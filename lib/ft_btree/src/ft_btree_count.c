/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:36:04 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:36:05 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

size_t				btree_count(t_btree *node)
{
	if (node == NULL)
		return (0);
	return (btree_count(node->left) + btree_count(node->right) + 1);
}

size_t				btree_maxlevel(t_btree *node)
{
	size_t			lhs;
	size_t			rhs;

	if (node == NULL)
		return (0);
	lhs = btree_maxlevel(node->left);
	rhs = btree_maxlevel(node->right);
	return (1 + ((rhs > lhs) ? rhs : lhs));
}

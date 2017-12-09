/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:09:29 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/24 16:03:26 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void			btree_clean(t_btree *root, void (*clr)())
{
	if (root == NULL)
		return ;
	btree_clean(root->left, clr);
	btree_clean(root->right, clr);
	clr(root->content);
	ft_memdel((void **)(&root));
}

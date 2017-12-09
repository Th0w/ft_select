/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:46:55 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/21 14:29:36 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree				*btree_create(void *content)
{
	t_btree			*ret;

	if ((ret = (t_btree *)ft_memalloc(sizeof(t_btree))) == NULL)
		return (NULL);
	ret->content = content;
	return (ret);
}

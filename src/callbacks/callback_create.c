/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:39:54 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 13:39:56 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		insert_handler(t_btree **handlers, int key,
									t_keyptr ptr)
{
	t_ptr		*tmp;
	t_btree		*node;

	if ((tmp = (t_ptr *)ft_memalloc(sizeof(t_ptr))) == NULL)
		return (-1);
	tmp->key = key;
	tmp->ptr = ptr;
	if ((node = btree_create(tmp)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	*handlers = btree_insert(*handlers, node, &ft_intcmp);
	return (1);
}

int				ft_add_actions(t_btree **actions)
{
	if (insert_handler(actions, FTK_ESC, &ft_handle_esc) == -1
		|| insert_handler(actions, FTK_NL, &ft_handle_nl) == -1
		|| insert_handler(actions, FTK_SP, &ft_handle_sp) == -1
		|| insert_handler(actions, FTK_DEL, &ft_handle_del) == -1)
		return (0);
	return (1);
}

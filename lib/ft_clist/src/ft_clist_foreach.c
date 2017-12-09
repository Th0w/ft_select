/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:37:16 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:37:17 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clist.h"

void			ft_clist_foreach(t_clist *head, void (*act)())
{
	t_clist		*curr;

	curr = head;
	while (1)
	{
		act(curr->content);
		curr = curr->next;
		if (curr->next == head)
			break ;
	}
}

void			ft_clist_foreach_data(t_clist *head, void (*act)(), void *data)
{
	t_clist		*curr;

	curr = head;
	while (1)
	{
		act(curr->content, data);
		curr = curr->next;
		if (curr->next == head)
			break ;
	}
}

void			ft_clist_foreach_if(t_clist *head, void (*act)(),
											int (*assert)())
{
	t_clist		*curr;

	curr = head;
	while (1)
	{
		if (assert(curr->content))
			act(curr->content);
		curr = curr->next;
		if (curr->next == head)
			break ;
	}
}

void			ft_clist_foreach_if_data(t_clist *head, void (*act)(),
											void *data, int (*assert)())
{
	t_clist		*curr;

	curr = head;
	while (1)
	{
		if (assert(curr->content))
			act(curr->content, data);
		curr = curr->next;
		if (curr->next == head)
			break ;
	}
}

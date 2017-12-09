/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:37:00 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:37:01 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clist.h"

void			ft_clist_clear(t_clist **lst, void (*ptr_free)())
{
	t_clist		*curr;
	t_clist		*tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	curr = *lst;
	curr->prev->next = NULL;
	while (curr->next != NULL)
	{
		tmp = curr;
		curr = curr->next;
		ptr_free(curr->content);
		free(curr);
	}
}

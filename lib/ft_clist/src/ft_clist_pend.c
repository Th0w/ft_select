/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_pend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:37:28 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:37:42 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clist.h"

void			*ft_clist_append(t_clist **lst, void *content)
{
	t_clist		*ret;

	if ((ret = ft_clist_new(content)) == NULL)
		return (NULL);
	if (*lst == NULL)
	{
		*lst = ret;
		ret->next = ret;
		ret->prev = ret;
	}
	else
	{
		(*lst)->prev->next = ret;
		ret->prev = (*lst)->prev;
		ret->next = *lst;
		(*lst)->prev = ret;
	}
	return (ret);
}

void			*ft_clist_prepend(t_clist **lst, void *content)
{
	t_clist		*ret;

	ret = ft_clist_append(lst, content);
	*lst = (*lst)->prev;
	return (ret);
}

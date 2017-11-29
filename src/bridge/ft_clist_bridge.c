/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_bridge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:48:35 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:36:38 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char			*ft_clist_tostr_if(t_clist *list, int (*assert)())
{
	char		*ret;
	char		*tmp;
	t_clist		*curr;

	curr = list;
	ret = NULL;
	while (1)
	{
		if (assert(curr->content))
		{
			tmp = ret;
			ret = ft_strjoinc(ret, ((t_arg *)(curr->content))->value, ' ');
			ft_strdel(&tmp);
		}
		curr = curr->next;
		if (curr->next == list)
			break ;
	}
	return (ret);
}

int				ft_clist_get_dist(t_clist *lhs, t_clist *rhs)
{
	int			dist;

	dist = 0;
	if (rhs != lhs)
	{
		while (lhs != rhs)
		{
			dist++;
			lhs = lhs->next;
		}
	}
	return (dist);
}

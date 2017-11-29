/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_bridge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:48:35 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:07:31 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		*ft_clear_clist(t_clist **lst)
{
	ft_clist_clear(lst, &free);
	return (NULL);
}

t_clist			*ft_clist_arg_to_list(int ac, char **av)
{
	t_clist		*ret;
	t_arg		*tmp;
	int			i;
	t_env		*env;
	size_t		len;

	ret = NULL;
	env = ft_sel_getenv();
	i = 0;
	while (i < ac)
	{
		if ((tmp = (t_arg *)ft_memalloc(sizeof(t_arg))) == NULL)
			return (ft_clear_clist(&ret));
		tmp->value = av[i];
		if ((len = ft_strlen(av[i])) > env->widest)
			env->widest = len;
		if (ft_clist_append(&ret, tmp) == NULL)
		{
			free(tmp);
			return (ft_clear_clist(&ret));
		}
		i++;
	}
	env->cnt = i;
	return (ret);
}

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

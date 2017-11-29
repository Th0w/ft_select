/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_get_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:23:01 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:36:43 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		*ft_clear_clist(t_clist **lst)
{
	ft_clist_clear(lst, &free);
	return (NULL);
}

static t_arg	*ft_create_arg(char *path)
{
	t_arg		*ret;
	t_stat		stats;

	if ((ret = (t_arg *)ft_memalloc(sizeof(t_arg))) == NULL)
		return (NULL);
	ret->value = path;
	if ((lstat(path, &stats)) == -1) 
		ret->type = ERRO;
	else
	{
		if (stats.st_mode & 0040000)
			ret->type |= DIRE;
		if (stats.st_mode & 0120000)
			ret->type |= LINK;
	}
	return (ret);
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
		if ((tmp = ft_create_arg(av[i])) == NULL)
			return (ft_clear_clist(&ret));
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



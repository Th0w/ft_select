/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:37:09 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:37:10 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clist.h"

t_clist			*ft_clist_new(void *content)
{
	t_clist		*ret;

	if ((ret = (t_clist *)ft_memalloc(sizeof(t_clist))) == NULL)
		return (NULL);
	ret->content = content;
	return (ret);
}

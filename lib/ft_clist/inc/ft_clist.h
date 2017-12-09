/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:39:56 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:40:13 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CLIST_H
# define FT_CLIST_H

# include "ft_mem.h"

typedef struct s_clist	t_clist;

struct			s_clist
{
	void		*content;
	t_clist		*prev;
	t_clist		*next;
};

t_clist			*ft_clist_new(void *content);
void			*ft_clist_append(t_clist **lst, void *content);
void			*ft_clist_prepend(t_clist **lst, void *content);
void			ft_clist_clear(t_clist **lst, void (*ptr_free)());
void			ft_clist_foreach(t_clist *head, void (*act)());
void			ft_clist_foreach_if(t_clist *head, void (*act)(),
									int (*assert)());
void			ft_clist_foreach_data(t_clist *head, void (*act)(), void *data);
void			ft_clist_foreach_if_data(t_clist *head, void (*act)(),
											void *data, int (*assert)());

#endif

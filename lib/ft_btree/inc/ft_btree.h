/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:13:49 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/24 16:03:05 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# include <stdlib.h>

# include "ft_mem.h"

typedef struct s_btree		t_btree;

struct						s_btree
{
	void					*content;
	t_btree					*left;
	t_btree					*right;
};

t_btree						*btree_create(void *content);

t_btree						*btree_insert(t_btree *root, t_btree *elem,
	   										int (*cmp)());
t_btree						*btree_insert_content(t_btree **root, void *content,
													int (*cmp)());

void						btree_foreach(t_btree *root, void (*act)());
void						btree_foreach_if(t_btree *root, void (*act)(),
												int (*assert)());
void						btree_foreach_data(t_btree *root, void (*act)(),
												void *data);
void						btree_foreach_if_data(t_btree *root, void (*act)(),
												int (*assert)(), void *data);

void						btree_postorder(t_btree *root, void (*act)());
void						btree_preorder(t_btree *root, void (*act)());

void						btree_clean(t_btree *root, void (*clr)());

size_t						btree_count(t_btree *root);
size_t						btree_maxlevel(t_btree *root);

/*
**							REV FOREACH
*/

void						btree_foreach_rev(t_btree *root, void (*act)());
void						btree_foreach_rev_if(t_btree *root, void (*act)(),
												int (*assert)());
void						btree_foreach_rev_data(t_btree *root, void (*act)(),
												void *data);
void						btree_foreach_rev_if_data(t_btree *root, void (*act)(),
												int (*assert)(), void *data);

t_btree						*btree_search(t_btree *root, void *content,
											 int (*assert)());

/*
**	TO BE TESTED
*/

void						btree_rotate_left(t_btree **root);
void						btree_rotate_right(t_btree **root);

/*
**	TO BE IMPLEMENTED.
*/

size_t						btree_min_height(t_btree *root);
size_t						btree_max_height(t_btree *root);


#endif

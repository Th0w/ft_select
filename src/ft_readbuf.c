/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:42:06 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 22:46:49 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		handle_nosch(char buf[4], t_env *env)
{
	t_btree		*node;

	node = NULL;
	if (buf[0] == '/')
	{
		ft_toggle_col(NULL, env);
		ft_print_args(env);
		return ;
	}
	node = btree_search(env->actions, (void *)buf, &ft_keycmp);
	if (node != NULL)
	{
		((t_ptr *)(node->content))->ptr(buf, env);
		ft_print_args(env);
	}
}

static void		handle_sch(char buf[4], t_env *env)
{
	if (buf[0] == FTK_ESC && buf[1] != FTK_BRA)
		ft_toggle_mode(env, FTK_RES);
	else if (buf[0] > 31 && buf[0] < 127)
		write(env->fd, buf, 4);
	else if (buf[0] == FTK_NL)
		ft_toggle_mode(env, FTK_RES);
}

void			ft_handle_buf(char buf[4], t_env *env)
{
	if (buf[0] == 4)
		ft_sel_exit();
	if (buf[0] == ':' || buf[0] == '?')
		ft_toggle_mode(env, buf[0]);
	else if ((env->mode & (SRCH | SRCI)) == 0)
		handle_nosch(buf, env);
	else
		handle_sch(buf, env);
}

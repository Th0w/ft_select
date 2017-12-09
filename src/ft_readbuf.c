/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readbuf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:42:06 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 11:22:47 by vbastion         ###   ########.fr       */
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

static void		print_prompt(t_env *env)
{
	hide_args(env);
	ft_print_args(env);
	ft_toggle_style(FT_TC_LL);
	write(env->fd, (env->mode & SRCH) != 0 ? ":" : "?", 1);
	write(env->fd, env->buf, env->buf_size);
}

static void		handle_select(t_env *env)
{
	t_clist		*curr;
	t_arg		*arg;

	curr = env->args;
	while (1)
	{
		arg = (t_arg *)(curr->content);
		if (arg->hidden == 0)
			arg->selected = 1;
		curr = curr->next;
		if (curr == env->args)
			break ;
	}
	ft_toggle_mode(env, FTK_RES);
}

static void		handle_sch(char buf[4], t_env *env)
{
	if (buf[0] == FTK_ESC && buf[1] != FTK_BRA)
		ft_toggle_mode(env, FTK_RES);
	else if (buf[0] > 31 && buf[0] < 127)
	{
		env->buf[env->buf_size] = buf[0];
		env->buf_size++;
		print_prompt(env);
	}
	else if (buf[0] == FTK_DEL)
	{
		if (env->buf_size == 0)
			return ;
		env->buf[env->buf_size] = '\0';
		env->buf_size--;
		print_prompt(env);
	}
	else if (buf[0] == FTK_NL)
		handle_select(env);
}

void			ft_handle_buf(char buf[4], t_env *env)
{
	if (buf[0] == 4)
		ft_sel_exit();
	if (((env->mode & (SRCH | SRCI)) == 0) && (buf[0] == ':' || buf[0] == '?'))
		ft_toggle_mode(env, buf[0]);
	else if ((env->mode & (SRCH | SRCI)) == 0)
		handle_nosch(buf, env);
	else
		handle_sch(buf, env);
}

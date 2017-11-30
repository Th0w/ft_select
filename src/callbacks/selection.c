/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:32:02 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/30 13:13:49 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_handle_esc(char buf[4], t_env *env)
{
	(void)env;
	if (buf[1] == 0)
		ft_sel_exit();
	if (buf[1] == 91 && buf[2] > 64 && buf[2] < 69)
		ft_clist_move((enum e_dir)(buf[2] - 65));
}

static int		is_selected(void *content)
{
	return (((t_arg *)content)->selected);
}

void			ft_handle_nl(char buf[4], t_env *env)
{
	int			one;
	t_clist		*curr;
	char		*str;

	(void)buf;
	one = 0;
	curr = env->args;
	ft_toggle_term(0);
	if ((str = ft_clist_tostr_if(env->args, &is_selected)) != NULL)
	{
		ft_putendl_fd(str, STDOUT_FILENO);
		ft_strdel(&str);
	}
	btree_clean(env->actions, &free);
	ft_clist_clear(&env->args, &free);
	close(env->fd);
	env->fd = -1;
	exit(0);
}

void			ft_handle_sp(char buf[4], t_env *env)
{
	t_arg		*arg;

	(void)buf;
	arg = (t_arg *)(env->hovered->content);
	arg->selected = !arg->selected;
	env->hovered = env->hovered->next;
}

void			ft_handle_del(char buf[4], t_env *env)
{
	t_clist		*elem;

	(void)buf;
	if (env->hovered->next == env->hovered)
		ft_sel_exit();
	else
	{
		if (env->hovered == env->args)
			env->args = env->args->next;
		elem = env->hovered;
		env->hovered = elem->next;
		env->hovered->prev = elem->prev;
		elem->prev->next = env->hovered;
		env->cnt--;
		free(elem->content);
		free(elem);
	}
}

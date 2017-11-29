/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:32:02 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 18:25:13 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_handle_esc(char *buffer, t_env *env)
{
	(void)env;
	if (buffer[1] == 0)
		ft_sel_exit();
	if (buffer[1] == 91 && buffer[2] > 64 && buffer[2] < 69)
		ft_clist_move((enum e_dir)(buffer[2] - 65));
}

static int		is_selected(void *content)
{
	return (((t_arg *)content)->selected);
}

void			ft_handle_nl(char *buffer, t_env *env)
{
	int			one;
	t_clist		*curr;
	char		*str;

	(void)buffer;
	one = 0;
	curr = env->args;
	ft_toggle_style("te");
	ft_toggle_style("ve");
	if ((str = ft_clist_tostr_if(env->args, &is_selected)) != NULL)
	{
		ft_toggle_term(0);
		ft_putendl_fd(str, 1);
		ft_strdel(&str);
	}
	ft_sel_exit();
}

void			ft_handle_sp(char *buffer, t_env *env)
{
	t_arg		*arg;

	(void)buffer;
	arg = (t_arg *)(env->hovered->content);
	arg->selected = !arg->selected;
	env->hovered = env->hovered->next;
}

void			ft_handle_del(char *buffer, t_env *env)
{
	t_clist		*elem;

	(void)buffer;
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

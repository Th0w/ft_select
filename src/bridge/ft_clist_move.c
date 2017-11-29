/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clist_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:35:13 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:08:42 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

#include <fcntl.h>

t_clist			*ft_clist_nmove(t_clist *list, int cnt)
{
	t_clist		*ret;
	int			fwd;

	if (list == NULL)
		return (NULL);
	ret = list;
	fwd = cnt > 0;
	while (cnt != 0)
	{
		ret = fwd ? ret->next : ret->prev;
		cnt += fwd ? -1 : 1;
	}
	return (ret);
}

static void		handle_down(t_env *env)
{
	int			pos;
	int			qty;
	int			row;

	pos = ft_clist_get_dist(env->args, env->hovered);
	if (pos < (env->cnt - env->arg_per_line))
		env->hovered = ft_clist_nmove(env->hovered, env->arg_per_line);
	else
	{
		row = pos / env->arg_per_line;
		qty = pos - (row * env->arg_per_line);
		env->hovered = ft_clist_nmove(env->args, qty);
	}
}

static void		handle_up(t_env *env)
{
	int			row;
	int			pos;
	int			qty;

	pos = ft_clist_get_dist(env->args, env->hovered);
	row = (pos == 0 ? 0 : (pos / env->arg_per_line));
	if (row != 0)
		env->hovered = ft_clist_nmove(env->hovered, -env->arg_per_line);
	else
	{
		row = env->cnt % env->arg_per_line;
		qty = -row + pos - (pos < row ? 0 : env->arg_per_line);
		env->hovered = ft_clist_nmove(env->args, qty);
	}
}

void			ft_clist_move(enum e_dir dir)
{
	t_env		*env;

	env = ft_sel_getenv();
	if (dir == LEFT)
		env->hovered = env->hovered->prev;
	else if (dir == RIGHT)
		env->hovered = env->hovered->next;
	else if (dir == UP)
		handle_up(env);
	else if (dir == DOWN)
		handle_down(env);
	else
		(void)(ft_error("Wrong move action.", -1) | ft_sel_exit());
}

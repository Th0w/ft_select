/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:10:24 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 22:40:49 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_toggle_col(char buf[4], t_env *env)
{
	(void)buf;
	env->mode ^= (DFLT | HGHL);
}

static void				ft_clear_hidden(t_env *env)
{
	(void)env;
}

static void				ft_restore_mode(t_env *env)
{
	env->mode &= ~(SRCH | SRCI);
	ft_print_args(env);
	ft_clear_hidden(env);
}

void					ft_toggle_mode(t_env *env, char mode)
{
	if (mode == -1)
		ft_restore_mode(env);
	else if ((env->mode & (SRCH | SRCI)) == 0)
	{
		env->mode |= (mode == ':' ? SRCH : SRCI);
		ft_toggle_style(FT_TC_LL);
		write(env->fd, &mode, 1);
	}
	else
		ft_restore_mode(env);
}

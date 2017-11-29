/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:19:20 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 13:41:14 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_create_term(t_env *env)
{
	if (tcgetattr(0, &env->old) == -1)
		return (-1);
	ft_memcpy((void *)&env->new, (const void *)&env->old, sizeof(t_term));
	env->new.c_lflag &= ~(ICANON);
	env->new.c_lflag &= ~(ECHO);
	env->new.c_cc[VMIN] = 1;
	env->new.c_cc[VTIME] = 0;
	return (1);
}

int				ft_calcdim(t_env *env)
{
	if (env->col < 8 && env->widest > 3)
		env->printer = &ft_print_nopad;
	else if ((env->arg_per_line = env->col / (env->widest + 4)) == 0)
	{
		env->arg_per_line = 1;
		env->printer = &ft_print_shrink;
	}
	else
		env->printer = &ft_print_padded;
	return (0);
}

int				ft_toggle_term(int on)
{
	t_env		*env;

	env = ft_sel_getenv();
	if (tcsetattr(0, TCSADRAIN, on ? &env->new : &env->old) == -1)
		return (-1);
	ft_toggle_style(on ? FT_TC_TI : FT_TC_TE);
	ft_toggle_style(on ? FT_TC_VI : FT_TC_VE);
	return (1);
}

int				ft_setup_env(int ac, char **av)
{
	t_env		*env;
	char		*name;

	env = ft_sel_getenv();
	if ((name = getenv(FT_TERM)) == NULL)
		return (ft_error(FT_NOENV, FT_NOENV_CODE));
	if (tgetent(0, name) == ERR)
		return (ft_error(FT_ETERM, 5));
	if (ft_add_actions(&env->actions) == 0)
		return (ft_error(FT_EACT, 4));
	ft_create_term(env);
	ft_addsignal();
	if ((env->args = ft_clist_arg_to_list(ac, av)) == NULL)
		return (ft_error(FT_EMEMALLOC, FT_MEMALLOC_CODE));
	ft_calcdim(env);
	env->hovered = env->args;
	return (0);
}

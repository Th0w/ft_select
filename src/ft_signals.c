/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:09:41 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:21:58 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_sigexit(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL
		|| signo == SIGTERM)
		ft_sel_exit();
}

static void		ft_sigpause(int signo)
{
	char		tmp[2];
	t_env		*env;

	if (signo != SIGTSTP)
		return ;
	env = ft_sel_getenv();
	ft_toggle_term(0);
	tmp[0] = env->old.c_cc[VSUSP];
	tmp[1] = '\0';
	ioctl(STDIN_FILENO, TIOCSTI, tmp);
	signal(SIGTSTP, SIG_DFL);
}

static void		ft_sigresume(int signo)
{
	if (signo != SIGCONT)
		return ;
	ft_toggle_term(1);
	ft_print_args(ft_sel_getenv());
	signal(SIGTSTP, &ft_sigpause);
}

static void		ft_sigresize(int signo)
{
	t_env		*env;

	if (signo != SIGWINCH)
		return ;
	env = ft_sel_getenv();
	ft_setenv_dim(&env->col, &env->row);
	ft_calcdim(env);
	ft_print_args(env);
}

void			ft_addsignal(void)
{
	signal(SIGINT, &ft_sigexit);
	signal(SIGQUIT, &ft_sigexit);
	signal(SIGKILL, &ft_sigexit);
	signal(SIGTERM, &ft_sigexit);
	signal(SIGTSTP, isatty(STDOUT_FILENO) ? &ft_sigpause : &ft_sigempty);
	signal(SIGCONT, &ft_sigresume);
	signal(SIGWINCH, &ft_sigresize);
}

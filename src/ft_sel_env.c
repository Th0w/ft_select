/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:09:35 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:44:18 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void				ft_setenv_dim(u_short *col, u_short *row)
{
	struct winsize	win;
	int				ret;
	t_env			*env;

	env = ft_sel_getenv();
	ret = ioctl(env->fd, TIOCGWINSZ, &win);
	if (ret == -1)
	{
		ft_putstr_fd(FT_ETTY, STDERR_FILENO);
		ft_toggle_term(0);
		exit (1);
		return ;
	}
	*col = win.ws_col;
	*row = win.ws_row;
}

t_env				*ft_sel_getenv(void)
{
	static t_env	env = (t_env){.init = 0};

	if (env.init == 0)
	{
		ft_bzero(&env, sizeof(t_env));
		env.fd = open("/dev/tty", O_WRONLY);
		if (env.fd == -1)
		{
			ft_putstr_fd("TTY and/or input error\n", STDERR_FILENO);
			exit(1);
		}
		env.init = 1;
		ft_setenv_dim(&env.col, &env.row);
	}
	return (&env);
}

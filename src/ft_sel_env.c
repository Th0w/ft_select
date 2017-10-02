#include "ft_select.h"

void				ft_setenv_dim(u_short *col, u_short *row)
{
	struct winsize	win;
	int				ret;

	ret = ioctl(0, TIOCGWINSZ, &win);
	if (ret == -1)
	{
		ft_putstr_fd(FT_ETTY, STDERR_FILENO);
		ft_sel_exit();
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
		ft_setenv_dim(&env.col, &env.row);
		env.init = 1;
	}
	return (&env);
}

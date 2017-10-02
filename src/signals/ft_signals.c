#include "ft_select.h"

void			ft_sigexit(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGKILL
		|| signo == SIGTERM)
		ft_sel_exit();
}

void			ft_sigpause(int signo)
{
	char		tmp[2];

	if (signo != SIGTSTP)
		return ;
	ft_toggle_term(0);
	tmp[0] = ft_sel_getenv()->old.c_cc[VSUSP];
	tmp[1] = '\0';
	ioctl(0, TIOCSTI, tmp);
	signal(SIGTSTP, SIG_DFL);
}

void			ft_sigresume(int signo)
{
	if (signo != SIGCONT)
		return ;
	ft_toggle_term(1);
	ft_print_args(ft_sel_getenv());
	signal(SIGTSTP, &ft_sigpause);
}

void			ft_sigresize(int signo)
{
	if (signo != SIGWINCH)
		return ;
	// RESIZE
}

void			ft_addsignal(void)
{
	signal(SIGINT, &ft_sigexit);
	signal(SIGQUIT, &ft_sigexit);
	signal(SIGKILL, &ft_sigexit);
	signal(SIGTERM, &ft_sigexit);
	signal(SIGTSTP, &ft_sigpause);
	signal(SIGCONT, &ft_sigresume);
	signal(SIGWINCH, &ft_sigresize);
}

#include "ft_select.h"

void			ft_sigexit(int signo)
{
	if (signo != SIGINT && signo != SIGTSTP)
		return ;
	ft_sel_exit();
}

void			ft_addsignal(void)
{
	signal(SIGINT, &ft_sigexit);
	signal(SIGTSTP, &ft_sigexit);
}

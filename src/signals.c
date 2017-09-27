#include "ft_select.h"

void			ft_sigexit(int signo)
{
	if (signo != SIGINT && signo != SIGTSTP)
		return ;
	ft_sel_exit();
}

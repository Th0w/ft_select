#include "ft_select.h"

int				ft_restore_term(void)
{
	if (tcsetattr(0, 0, &ft_sel_getenv()->old) == -1)	
		return (0);
	return (1);
}

int				ft_change_term(t_term *new)
{
	t_term		*old;

	old = &ft_sel_getenv()->old;
	if (tcgetattr(0, old) == -1)
		return (-1);
	ft_memcpy(new, old, sizeof(t_term));
	(*new).c_lflag &= ~(ICANON);
	(*new).c_lflag &= ~(ECHO);
	(*new).c_cc[VMIN] = 1;
	(*new).c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, new) == -1)
		return (-1);
	return (1);
}

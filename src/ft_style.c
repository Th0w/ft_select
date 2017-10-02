#include "ft_select.h"

int				ft_putfd0(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

void			ft_toggle_style(char *style)
{
	char		*tmp;

	if ((tmp = tgetstr(style, NULL)) == NULL)
		return ;
	tputs(tmp, 1, &ft_putfd0);
}

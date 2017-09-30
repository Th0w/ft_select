#include "ft_select.h"

void			ft_toggle_style(char *style)
{
	ft_toggle_style_cnt(style, 1);
}

void			ft_toggle_style_cnt(char *style, int cnt)
{
	char		*tmp;

	if ((tmp = tgetstr(style, NULL)) == NULL)
		return ;
	tputs(tmp, cnt, &ft_putchar);
}

void			ft_move_cursor(int x, int y)
{
	char		*cm;
	char		*gotostr;

	cm = tgetstr(FT_TC_CM, NULL);
	gotostr = tgoto(cm, x, y);
	tputs(gotostr, 1, &ft_putchar);
}

int				ft_get_cursor_pos(int *x, int *y)
{
	char		buffer[21];
	int			ret;
	char		*tmp;

	ft_putstr(FT_TC_GETMPOS);
	ft_bzero(buffer, 21);
	read(0, buffer, 20);
	tmp = NULL;
	ret = ft_getnumber(buffer, &tmp, x);
	ret |= ft_getnumber(tmp, NULL, y);
	if (ret != 0)
		return (-1);
	return (1);
}

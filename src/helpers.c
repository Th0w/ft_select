#include "ft_select.h"

size_t			ft_selstrlen(const char *str)
{
	size_t		len;

	len = 0;
	if (str == NULL)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

int				ft_sel_exit(void)
{
	ft_restore_term();
	ft_clist_clear(&ft_sel_getenv()->args, &free);
	exit(0);
	return (0);
}

int				ft_error(const char *err_msg, const int err_code)
{
	size_t		len;
	len = 0;
	while (err_msg[len] != '\0')
		len++;
	write(2, "\033[91mERROR: \033[0m", 16);
	write(2, err_msg, len);
	return (err_code);
}

int				ft_putchar(int c)
{
	write(STDIN_FILENO, &c, 1);
	return (0);
}

void			ft_toggle_style(char *style, int cnt)
{
	char		*tmp;

	if ((tmp = tgetstr(style, NULL)) == NULL)
	{
		dprintf(2, "Wrong termcaps identifier.\n");
		return ;
	}
	tputs(tmp, cnt, &ft_putchar);
}

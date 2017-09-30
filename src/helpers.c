#include "ft_select.h"

int				ft_sel_exit(void)
{
	ft_restore_term();
	ft_clist_clear(&ft_sel_getenv()->args, &free);
	ft_toggle_style("ve");
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

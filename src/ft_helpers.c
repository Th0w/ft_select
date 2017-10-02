#include "ft_select.h"

int				ft_sel_exit(void)
{
	t_env		*env;

	env = ft_sel_getenv();
	btree_clean(env->actions, &free);
	btree_clean(env->handlers, &free);
	ft_clist_clear(&env->args, &free);
	ft_toggle_term(0);
	exit(0);
	return (0);
}

int				ft_error(const char *err_msg, const int err_code)
{
	ft_putstr_fd("\033[91mERROR: \033[0m", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	return (err_code);
}

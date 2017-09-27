#include "ft_select.h"

t_env			*ft_sel_getenv(void)
{
	static t_env	env = (t_env){.init = 0};

	if (env.init == 0)
	{
		ft_bzero(&env, sizeof(t_env));
		env.init = 1;
	}
	return (&env);
}

int				ft_sel_exit(void)
{
	ft_restore_term();
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

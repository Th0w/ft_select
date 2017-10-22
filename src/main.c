#include "ft_select.h"

static int		ft_usage(const char *name)
{
	tputs("\033[33m", 1, &ft_putfd0);
	ft_putstr("usage: ");
	tputs("\033[0m", 1, &ft_putfd0);
	ft_putstr(name);
	ft_putstr(" [file ...]\n");
	return (1);
}

static int		core_loop(void)
{
	t_env		*env;
	char		buffer[4];
	t_btree		*node;
	size_t		ret;

	env = ft_sel_getenv();
	ft_print_args(env);
	while (1)
	{
		node = NULL;
		*((int *)buffer) = 0;
		if ((ret = read(0, buffer, 3)) == (size_t)(-1))
			return (ft_sel_exit());
		if (buffer[0] == 4)
			break ;
		node = btree_search(env->actions, (void *)buffer, &ft_keycmp);
		if (node != NULL)
		{
			((t_ptr *)(node->content))->ptr(buffer, env);
			ft_print_args(env);
		}
	}
	return (ft_sel_exit());
}

int				main(int ac, char **av)
{
	int			ret;

	if (ac == 1)
		return (ft_usage(av[0]));
	if ((ret = ft_setup_env(ac - 1, av + 1)) != 0)
		return (ret);
	ft_toggle_term(1);
	core_loop();
	return (0);
}

#include <unistd.h>
#include <stdio.h> //

#include "ft_select.h"

int				main_loop(void)
{
	t_env		*env;
	char		*buffer[4];
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
		node = btree_search(env->actions, (void *)buffer, &ft_keycmp);
		if (node != NULL)
		{
			((t_ptr *)(node->content))->ptr(buffer, env);
			ft_print_args(env);
		}
	}
	ft_sel_exit();
}

int				main(int ac, char **av)
{
	int			ret;

	if (ac == 1)
		return (0);
	if ((ret = ft_setup_env(ac - 1, av + 1)) != 0)
		return (ret);
	ft_toggle_term(1);
	main_loop();
	return (0);
}

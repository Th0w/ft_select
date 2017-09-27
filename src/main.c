#include <unistd.h>
#include <stdio.h> //

#include "ft_select.h"

int				show_keys(t_btree *handlers)
{
	char		buffer[4];
	t_btree		*node;
	int			ret;

	while (1)
	{
		node = NULL;
		*((int *)buffer) = 0;
		if ((ret = read(0, buffer, 3)) == -1)
			return (ft_error("Could not read.\n", 3));
		if (*buffer == 4 || (buffer[0] == 27 && buffer[1] != 91))
			return (ft_sel_exit());
		if (buffer[0] == FTK_ESC)
		{
			node = btree_search(handlers, (void *)buffer, &ft_intptrcmp);
			if (node != NULL)
				((t_ptr *)(node->content))->ptr();
			else
				dprintf(2, "No handler for this key!\n");
		}
		else if (buffer[0] == FTK_NL)
			printf("NEWLINE, BITCH\n");
		else if (buffer[0] == FTK_SP)
			printf("SPACE, BITCH\n");
		else if (buffer[0] == FTK_DEL)
			printf("DEL, BITCH\n");
		else
			dprintf(2, "No handler for this key!\n");
	}
}

int				main_loop(void)
{
	t_clist		*args;
	t_env		*env;
	char		*buffer[4];
	t_btree		*node;
	size_t		ret;

	env = ft_sel_getenv();
	args = env->args;
	env->hovered = (t_arg *)(args->content);
	ft_print_args(env, args);
	while (1)
	{
		node = NULL;
		*((int *)buffer) = 0;
		if ((ret = read(0, buffer, 3)) == (size_t)-1)
			return (ft_error("Could not read.\n", 3) | ft_sel_exit());
		node = btree_search(env->actions, (void *)buffer, &ft_keycmp);
		if (node != NULL)
		{
			((t_ptr *)(node->content))->ptr();
			ft_print_args(env, args);
		}
		else
			dprintf(2, "No handler for this key!\n");
	}
	ft_sel_exit();
}

int				main(int ac, char **av)
{
	char		*name;
	t_term		new;
	t_env		*env;

	if (ac == 1)
		return (0);
	env = ft_sel_getenv();
	if ((name = getenv(FT_TERM)) == NULL)
		return (ft_error(FT_NOENV, FT_NOENV_CODE));
	if (tgetent(0, name) == ERR)
		return (1);
	ft_change_term(&new);
	if (ft_add_actions(&env->actions) == 0
		|| ft_add_handlers(&env->handlers) == 0)
		return (ft_error("Could not set actions\n", 4) | ft_sel_exit());;
	signal(SIGINT, &ft_sigexit);
	signal(SIGTSTP, &ft_sigexit);
	if ((env->args = ft_clist_arg_to_list(ac - 1, av + 1)) == NULL)
		return (ft_error(FT_MEMALLOC, FT_MEMALLOC_CODE) | ft_sel_exit());
	env->arg_per_line = env->col / (env->widest + 4);
	main_loop();
	return (0);
}

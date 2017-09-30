#include <unistd.h>
#include <stdio.h> //

#include "ft_select.h"

int				main_loop(void)
{
	t_clist		*args;
	t_env		*env;
	char		*buffer[4];
	t_btree		*node;
	size_t		ret;

	env = ft_sel_getenv();
	args = env->args;
	env->hovered = args;
	ft_print_args(env, args);
	while (1)
	{
		node = NULL;
		*((int *)buffer) = 0;
		if ((ret = read(0, buffer, 3)) == (size_t) - 1)
			return (ft_sel_exit());
		node = btree_search(env->actions, (void *)buffer, &ft_keycmp);
		if (node != NULL)
		{
			((t_ptr *)(node->content))->ptr(buffer, env);
			ft_move_cursor(0, env->x - 1);
			ft_toggle_style(FT_TC_CD);
			ft_print_args(env, args);
		}
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
	env->line_count = (int)((double)env->cnt / env->arg_per_line + .5);
	ft_toggle_style("vi");
	ft_get_cursor_pos(&env->x, &env->y);
	if (env->x + env->line_count > env->row)
		env->x = env->row - env->line_count - 1;
	main_loop();
	return (0);
}

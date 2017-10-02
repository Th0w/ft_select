#include "ft_select.h"

void			ft_mv_up(void)
{
	t_env		*env;

	env = ft_sel_getenv();
	env->hovered = ft_clist_move(env->hovered, -env->arg_per_line);
	return ;
}

void 			ft_mv_down(void)
{
	t_env		*env;

	env = ft_sel_getenv();
	env->hovered = ft_clist_move(env->hovered, env->arg_per_line);
	return ;
}

void 			ft_mv_left(void)
{
	ft_sel_getenv()->hovered = ft_sel_getenv()->hovered->prev;
	return ;
}

void 			ft_mv_right(void)
{
	ft_sel_getenv()->hovered = ft_sel_getenv()->hovered->next;
	return ;
}

#include "ft_select.h"

void			ft_handle_esc(char *buffer, t_env *env)
{
	t_btree		*node;

	if (buffer[1] == 0)
		ft_sel_exit();
	node = btree_search(env->handlers, (void *)buffer, &ft_intptrcmp);
	if (node != NULL)
		((t_ptr *)(node->content))->ptr();
}

static int		is_selected(void *content)
{
	return (((t_arg *)content)->selected);
}

void			ft_handle_nl(char *buffer, t_env *env)
{
	int			one;
	t_clist		*curr;
	char		*str;

	(void)buffer;
	one = 0;
	curr = env->args;
	ft_toggle_style("te");
	ft_toggle_style("ve");
	if ((str = ft_clist_tostr_if(env->args, &is_selected)) != NULL)
	{
		ft_putendl_fd(str, STDOUT_FILENO);
		ft_strdel(&str);
	}
	exit(0);
}

void			ft_handle_sp(char *buffer, t_env *env)
{
	t_arg		*arg;

	(void)buffer;
	arg = (t_arg *)(env->hovered->content);
	arg->selected = !arg->selected;
	env->hovered = env->hovered->next;
}

void			ft_handle_del(char *buffer, t_env *env)
{
	(void)buffer;
	t_clist		*elem;

	if (env->hovered->next == env->hovered)
		ft_sel_exit();
	else
	{
		if (env->hovered == env->args)
			env->args = env->args->next;
		elem = env->hovered;
		env->hovered = elem->next;
		env->hovered->prev = elem->prev;
		elem->prev->next = env->hovered;
		free(elem->content);
		free(elem);
	}
}

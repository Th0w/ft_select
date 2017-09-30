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

void			ft_handle_nl(char *buffer, t_env *env)
{
	int			one;
	t_clist		*curr;

	(void)buffer;
	one = 0;
	curr = env->args;
	while (1)
	{
		if (((t_arg *)(curr->content))->selected)
		{
			if (one)
				write(1, " ", 1);
			one = 1;
			ft_putstr_fd(((t_arg *)(curr->content))->value, 1);
		}
		curr = curr->next;
		if (curr == env->args)
		{
			if (one)
				ft_putstr_fd("\n", 1);
			ft_sel_exit();
		}
	}
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
	(void)env;
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

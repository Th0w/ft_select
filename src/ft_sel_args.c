#include "ft_select.h"

static void		ft_print_arg(void *content, void *data)
{
	t_arg		*arg;
	t_env		*env;
	size_t		len;
	int			selected;

	env = (t_env *)data;
	arg = (t_arg *)content;
	len = ft_selstrlen(arg->value);
	selected = arg == env->hovered;
	if (arg->selected == 1)
		ft_toggle_style(FT_SEL_REV, 1);
	if (selected)
		ft_toggle_style(FT_SEL_ULON, 1);
	dprintf(0, "%c %-*s %c", selected ? '>' : ' ', (int)env->widest, arg->value, selected ? '<' : ' ');
	if (arg == env->hovered)
		ft_toggle_style(FT_SEL_ULOFF, 1);
	if (arg->selected == 1)
		ft_toggle_style(FT_SEL_CLR, 1);
	env->curr++;
}

void			ft_print_args(t_env *env, t_clist *head)
{
	t_clist		*curr;
	int			progress;

	env = ft_sel_getenv();
	head = env->args;
	curr = head;
	progress = 0;
	while (1)
	{
		ft_print_arg(curr->content, (void *)env);
		if (curr->next == head)
			break ;
		curr = curr->next;
		progress++;
		if ((progress % env->arg_per_line) == 0) 
			write(0, "\n", 1);
	}
	write(0, "\n", 1);
}

#include "ft_select.h"

static void		ft_print_arg(t_clist *elem, t_env *env)
{
	t_arg		*arg;
	size_t		len;
	int			selected;

	arg = (t_arg *)(elem->content);
	len = ft_strlen(arg->value);
	selected = elem == env->hovered;
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_REV);
	if (selected)
		ft_toggle_style(FT_TC_ULON);
	dprintf(0, "%c %-*s %c", selected ? '>' : ' ', (int)env->widest, arg->value, selected ? '<' : ' ');
	if (selected)
		ft_toggle_style(FT_TC_ULOFF);
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_CLR);
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
		ft_print_arg(curr, (void *)env);
		if (curr->next == head)
			break ;
		curr = curr->next;
		progress++;
		if ((progress % env->arg_per_line) == 0) 
			write(0, "\n", 1);
	}
	write(0, "\n", 1);
}

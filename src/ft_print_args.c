#include "ft_select.h"

void			ft_print_padded(char *value, t_env *env, int hovered)
{
	size_t		len;

	len = ft_strlen(value);
	ft_putstr_fd(hovered ? "> " : "  ", STDIN_FILENO);
	ft_putstr_fd(value, STDIN_FILENO);
	ft_putblank_fd(env->widest - len, STDIN_FILENO);
	ft_putstr_fd(hovered ? " <" : "  ", STDIN_FILENO);
}

void			ft_print_shrink(char *value, t_env *env, int hovered)
{
	size_t		len;
	size_t		rem;

	len = ft_strlen(value);
	rem = env->col - 4;
	ft_putstr_fd(hovered ? "> " : "  ", STDIN_FILENO);
	if (len > rem)
	{
		write(STDIN_FILENO, value, rem - 3);
		write(STDIN_FILENO, "...", 3);
	}
	else
	{
		ft_putstr_fd(value, STDIN_FILENO);
		ft_putblank_fd(rem - len, STDIN_FILENO);
	}
	ft_putstr_fd(hovered ? " <" : "  ", STDIN_FILENO);
}

void			ft_print_nopad(char *value, t_env *env, int hovered)
{
	size_t		len;

	(void)hovered;
	len = ft_strlen(value);
	if (env->col < 4 && len >= 4)
		write(STDIN_FILENO, value, env->col);
	else if (len > env->col)
	{
		write(STDIN_FILENO, value, len - 3);
		write(STDIN_FILENO, "...", 3);
	}
	else
		write(STDIN_FILENO, value, len);
}

static void		ft_print_arg(t_clist *elem, t_env *env)
{
	t_arg		*arg;
	int			hovered;

	arg = (t_arg *)(elem->content);
	hovered = elem == env->hovered;
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_REV);
	if (hovered)
		ft_toggle_style(FT_TC_ULON);
	env->printer(arg->value, env, hovered);
	if (hovered)
		ft_toggle_style(FT_TC_ULOFF);
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_CLR);
	env->curr++;
}

void			ft_print_args(t_env *env)
{
	t_clist		*curr;
	int			progress;

	ft_toggle_style(FT_TC_CL);
	curr = env->args;
	progress = 0;
	while (1)
	{
		ft_print_arg(curr, (void *)env);
		if (curr->next == env->args)
			break ;
		curr = curr->next;
		progress++;
		if ((progress % env->arg_per_line) == 0) 
			write(0, "\n", 1);
	}
	write(0, "\n", 1);
}

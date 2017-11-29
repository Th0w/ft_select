/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:09:50 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 18:36:43 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		add_color(t_env *env, t_arg *elem)
{
	if (elem->type == ERRO)
		ft_putstr_fd("\033[2m", env->fd);
	else if ((elem->type & (DIRE | LINK)) == (DIRE | LINK))
		ft_putstr_fd("\033[32m", env->fd);
	else if (elem->type == DIRE)
		ft_putstr_fd("\033[36m", env->fd);
	else if (elem->type == LINK)
		ft_putstr_fd("\033[95m", env->fd);
	return (elem->type != REGU);
}

static void		ft_print_arg(t_clist *elem, t_env *env)
{
	t_arg		*arg;
	int			hovered;
	int			colored;

	arg = (t_arg *)(elem->content);
	hovered = elem == env->hovered;
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_REV);
	if (hovered)
		ft_toggle_style(FT_TC_ULON);
	colored = add_color(env, arg);
	env->printer(arg->value, env, hovered);
	if (hovered)
		ft_toggle_style(FT_TC_ULOFF);
	if (arg->selected == 1)
		ft_toggle_style(FT_TC_CLR);
	if (colored)
		ft_putstr_fd("\033[0m", env->fd);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:10:48 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:11:03 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_toggle_exe(char buf[4], t_env *env)
{
	t_clist				*curr;
	t_arg				*arg;

	(void)buf;
	curr = env->args;
	while (1)
	{
		arg = (t_arg *)curr->content;
		if (arg->type == EXEC)
			arg->selected = 1;
		curr = curr->next;
		if (curr == env->args)
			break ;
	}
}

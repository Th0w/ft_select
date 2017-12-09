/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:21:53 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 11:22:53 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			hide_args(t_env *env)
{
	t_clist		*curr;
	t_arg		*arg;
	size_t		len;

	curr = env->args;
	while (1)
	{
		arg = (t_arg *)(curr->content);
		len = ft_strlen(arg->value);
		if (len < (size_t)env->buf_size)
			arg->hidden = 1;
		else
		{
			len = (size_t)env->buf_size;
			arg->hidden = ft_match(arg->value, env->buf, len, env) == 0;
		}
		curr = curr->next;
		if (curr == env->args)
			break ;
	}
}

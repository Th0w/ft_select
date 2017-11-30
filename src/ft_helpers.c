/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:43:41 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:45:40 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_sel_exit(void)
{
	t_env		*env;

	env = ft_sel_getenv();
	btree_clean(env->actions, &free);
	ft_clist_clear(&env->args, &free);
	ft_toggle_term(0);
	if (env->fd != -1)
		close(env->fd);
	env->fd = -1;
	exit(0);
	return (0);
}

int				ft_error(const char *err_msg, const int err_code)
{
	ft_putstr_fd("\033[91mERROR: \033[0m", STDERR_FILENO);
	ft_putstr_fd(err_msg, STDERR_FILENO);
	return (err_code);
}

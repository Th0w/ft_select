/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptrs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:36:25 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 18:36:41 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_print_padded(char *value, t_env *env, int hovered)
{
	size_t		len;

	len = ft_strlen(value);
	ft_putstr_fd(hovered ? "> " : "  ", env->fd);
	ft_putstr_fd(value, env->fd);
	ft_putblank_fd(env->widest - len, env->fd);
	ft_putstr_fd(hovered ? " <" : "  ", env->fd);
}

void			ft_print_shrink(char *value, t_env *env, int hovered)
{
	size_t		len;
	size_t		rem;

	len = ft_strlen(value);
	rem = env->col - 4;
	ft_putstr_fd(hovered ? "> " : "  ", env->fd);
	if (len > rem)
	{
		write(env->fd, value, rem - 3);
		write(env->fd, "...", 3);
	}
	else
	{
		ft_putstr_fd(value, env->fd);
		ft_putblank_fd(rem - len, env->fd);
	}
	ft_putstr_fd(hovered ? " <" : "  ", env->fd);
}

void			ft_print_nopad(char *value, t_env *env, int hovered)
{
	size_t		len;

	(void)hovered;
	len = ft_strlen(value);
	if (env->col < 4 && len >= 4)
		write(env->fd, value, env->col);
	else if (len > env->col)
	{
		write(env->fd, value, len - 3);
		write(env->fd, "...", 3);
	}
	else
		write(env->fd, value, len);
}

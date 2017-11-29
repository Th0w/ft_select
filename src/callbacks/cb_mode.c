/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_mode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:10:24 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 19:10:38 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void					ft_toggle_col(char *buffer, t_env *env)
{
	(void)buffer;
	if (env->mode == DFLT)
		env->mode = HGHL;
	else if (env->mode == HGHL)
		env->mode = DFLT;
}
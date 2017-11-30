/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_style.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:19:28 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 13:19:29 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			ft_toggle_style(char *style)
{
	char		*tmp;

	if ((tmp = tgetstr(style, NULL)) == NULL)
		return ;
	write(ft_sel_getenv()->fd, tmp, ft_strlen(tmp));
}

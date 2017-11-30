/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:33:22 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/30 12:45:06 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_match_icase(char *str, char *buf, size_t len)
{
	size_t		i;
	char		a;
	char		b;

	i = 0;
	while (i < len)
	{
		a = str[i] >= 'A' && str[i] <= 'Z' ? str[i] + 0x20 : str[i];
		b = buf[i] >= 'A' && buf[i] <= 'Z' ? buf[i] + 0x20 : buf[i];
		if (b != '*' && a != b)
			return (0);
		i++;
	}
	return (1);
}

int				ft_match(char *str, char *buf, size_t len, t_env *env)
{
	size_t		i;

	if ((env->mode & SRCI) != 0)
		return (ft_match_icase(str, buf, len));
	i = 0;
	while (i < len)
	{
		if (buf[i] != '*' && buf[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

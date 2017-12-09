/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:35:53 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 18:59:58 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strdup(const char *s1)
{
	unsigned short	len;
	unsigned short	i;
	char			*ret;

	len = 0;
	while (*(s1 + len))
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(ret + len) = '\0';
	i = 0;
	while (i != len)
	{
		*(ret + i) = *(s1 + i);
		i++;
	}
	return (ret);
}

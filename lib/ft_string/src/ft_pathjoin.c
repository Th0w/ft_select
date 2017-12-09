/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:11:18 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 19:04:10 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_pathjoin(char *path, char *name)
{
	char		*ret;
	size_t		len_path;
	size_t		len_name;

	len_path = ft_strlen(path);
	len_name = ft_strlen(name);
	ret = (char *)malloc(sizeof(char) * (len_name + len_path + 2));
	if (ret == NULL)
		return (NULL);
	ft_strncat(ret, path, len_path);
	ret[len_path] = '/';
	ft_strncat(ret, name, len_name);
	ret[len_path + 1 + len_name] = '\0';
	return (ret);
}

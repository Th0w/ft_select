/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:09:00 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 17:09:01 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				ft_intcmp(int lhs, int rhs)
{
	return (lhs - rhs);
}

int				ft_intptrcmp(void *lhs, void *rhs)
{
	return (((t_ptr *)lhs)->key - *((int *)(char *)rhs));
}

int				ft_keycmp(void *lhs, void *rhs)
{
	return (((t_ptr *)lhs)->key - *((char *)rhs));
}

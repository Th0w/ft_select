/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:03:38 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 22:46:39 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_usage(const char *name)
{
	tputs("\033[33m", 1, &ft_putfd0);
	ft_putstr("usage: ");
	tputs("\033[0m", 1, &ft_putfd0);
	ft_putstr(name);
	ft_putstr(" [file ...]\n");
	return (1);
}

static int		core_loop(void)
{
	t_env		*env;
	char		buf[4];
	size_t		ret;

	env = ft_sel_getenv();
	ft_print_args(env);
	while (1)
	{
		*((int *)buf) = 0;
		if ((ret = read(0, buf, 3)) == (size_t)(-1))
			return (ft_sel_exit());
		ft_handle_buf(buf, env);
	}
	return (ft_sel_exit());
}

int				main(int ac, char **av)
{
	int			ret;

	if (ac == 1)
		return (ft_usage(av[0]));
	if ((ret = ft_setup_env(ac - 1, av + 1)) != 0)
		return (ret);
	ft_toggle_term(1);
	core_loop();
	return (0);
}

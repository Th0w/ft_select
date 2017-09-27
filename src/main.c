#include <unistd.h>
#include <stdio.h> //

#include "ft_select.h"

int				show_keys(t_btree *handlers)
{
	char		buffer[4];
	t_btree		*node;
	int			ret;

	while (1)
	{
		node = NULL;
		*((int *)buffer) = 0;
		if ((ret = read(0, buffer, 3)) == -1)
			return (ft_error("Could not read.\n", 3));
		if (*buffer == 4 || (buffer[0] == 27 && buffer[1] != 91))
			return (ft_sel_exit());
		if (buffer[0] == FTK_ESC)
		{
			node = btree_search(handlers, (void *)buffer, &ft_intptrcmp);
			if (node != NULL)
				((t_ptr *)(node->content))->ptr();
			else
				dprintf(2, "No handler for this key!\n");
		}
		else if (buffer[0] == FTK_NL)
			printf("NEWLINE, BITCH\n");
		else if (buffer[0] == FTK_SP)
			printf("SPACE, BITCH\n");
		else if (buffer[0] == FTK_DEL)
			printf("DEL, BITCH\n");
		else
			dprintf(2, "No handler for this key!\n");
	}
}

int				main(int ac, char **av)
{
	t_clist		*args;
	char		*name;
	t_term		new;
	int			ret;
	t_btree		*btree_handlers;

	if ((name = getenv(FT_TERM)) == NULL)
		return (ft_error(FT_NOENV, FT_NOENV_CODE));
	if (tgetent(0, name) == ERR)
		return (1);
	btree_handlers = NULL;
	if (ft_add_handlers(&btree_handlers) == 0)
		return (1);
	ft_change_term(&new);
	signal(SIGINT, &ft_sigexit);
	signal(SIGTSTP, &ft_sigexit);
	if ((ret = show_keys(btree_handlers)) != 0)
		return (ret);
	return (0);
	if (ac == 1)
		return (ft_error("No args given\n", 1));
	if ((args = ft_clist_fromarr((void **)(av + 1))) == NULL)
		return (ft_error(FT_MEMALLOC, FT_MEMALLOC_CODE));
	return (0);
}

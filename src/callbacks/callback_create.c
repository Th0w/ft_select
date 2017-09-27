#include "ft_select.h"

static int		insert_handler(t_btree **handlers, int key,
									t_keyptr ptr)
{
	t_ptr		*tmp;
	t_btree		*node;

	if ((tmp = (t_ptr *)ft_memalloc(sizeof(t_ptr))) == NULL)
		return (-1);
	tmp->key = key;
	tmp->ptr = ptr;
	if ((node = btree_create(tmp)) == NULL)
	{
		free(tmp);
		return (-1);
	}
	*handlers = btree_insert(*handlers, node, &ft_intcmp);
	return (1);
}

int				ft_add_handlers(t_btree **handlers)
{
	if (insert_handler(handlers, FTK_UP, &ft_mv_up) == -1
		|| insert_handler(handlers, FTK_DOWN, &ft_mv_down) == -1
		|| insert_handler(handlers, FTK_RIGHT, &ft_mv_right) == -1
		|| insert_handler(handlers, FTK_LEFT, &ft_mv_left) == -1)
	{
		dprintf(2, "Could not insert a callback!\n");
		return (0);
	}
	return (1);
}

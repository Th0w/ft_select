#include <unistd.h>

#include "ft_clist.h"

void			print(const char *str)
{
	size_t		len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

int				main(int ac, char **av)
{
	t_clist		*head;
	t_clist		*curr;
	int			i;

	(void)av;
	head = NULL;
	clst_append(&head, av[0]);
//	clst_prepend(&head, av[0]);
	if (ac != 1)
	{
		for (i = 1; i < ac; i++)
			clst_append(&head, av[i]);
//			clst_prepend(&head, av[i]);
	}
	curr = head;
	do
	{
		print((char *)(curr->content));
		print("\n");
		curr = curr->next;
	} while (curr->content != head->content);
	return (0);
}

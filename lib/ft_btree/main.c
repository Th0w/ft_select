#include "ft_btree.h"
#include "ft_mem.h"
#include "ft_printf.h"
#include "ft_string.h"

#define NAME_MAX 255

typedef struct		s_test
{
	int				type;
	char			name[NAME_MAX];
}					t_test;

t_test				*test_create(char *name, int type)
{
	size_t			len;
	t_test			*test;

	len = ft_strlen(name);
	if (len > NAME_MAX)
		return (NULL);
	else if ((test = (t_test *)ft_memalloc(sizeof(t_test))) == NULL)
		return (NULL);
	ft_strncpy(test->name, name, len);
	test->type = type;
	return (test);
}

int					test_cmp(void *lhs, void *rhs)
{
	t_btree			*elem = (t_btree *)lhs,
					*root = (t_btree *)rhs;
	t_test			*tlhs = (t_test *)elem->content,
					*trhs = (t_test *)root->content;

//	ft_printf("Comparing '%s' ans '%s'\n", tlhs->name, trhs->name);
	return (ft_strcmp(tlhs->name, trhs->name));
}

void				test_print(void *content)
{
	t_test			*test;

	test = (t_test *)content;
	ft_putendl(test->name);
}

void				test_free(void *content)
{
	ft_memdel((void **)(&content));
}

int					test_find_by_name(void *content, void *name)
{
	return ((ft_strcmp(((t_test *)content)->name, (char *)name)));
}

int main(int ac, char **av)
{
	char			*objects[25] = {
		(char *)("Wololo"), (char *)("Walala"), (char *)("Welele"),
		(char *)("Turd"), (char *)("Background"), (char *)("Flixel"),
		(char *)("Android"), (char *)("Restroom"), (char *)("Black Devil"),
		(char *)("Daredevil"), (char *)("Luke"), (char *)("Jedi"),
		(char *)("Mind"), (char *)("Trick"), (char *)("ELem"),
		(char *)("Working"), (char *)("A wok"), (char *)("Iron"),
		(char *)("Fist"), (char *)("First"), (char *)("Mage"),
		(char *)("War"), (char *)("God"), (char *)("Zorg"),  NULL
	};
	t_btree			*head;
	t_btree			*tmp_node;
	t_test			*tmp_test;
	int				i;

	head = NULL;
	for (i = 0; objects[i] != NULL; i++)
	{
		tmp_test = test_create(objects[i], 1);
		tmp_node = btree_create(tmp_test);
		head = btree_insert(head, tmp_node, test_cmp);
	}
	ft_printf("Node count: %d\n", btree_count(head));
	ft_printf("Node max depth: %d\n", btree_maxlevel(head));
//	btree_foreach(head, test_print);
//	btree_foreach_rev(head, test_print);
	
//	char *to_find = "God";
//	t_btree *node_Zorg = btree_search(head, to_find, test_find_by_name);
//	if (node_Zorg != NULL)
//	{
//		ft_putstr("Found '");
//		ft_putstr(to_find);
//		ft_putstr("'.\n");
//	}
//	else
//		ft_putstr("Does not work.\n");
	btree_clean(head, test_free);
	return (0);
}

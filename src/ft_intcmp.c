#include "ft_select.h"

int				ft_intcmp(int lhs, int rhs)
{
	return (lhs - rhs);
}

int				ft_intptrcmp(void *lhs, void *rhs)
{
	return (((t_ptr *)lhs)->key - *((int *)(char *)rhs));
}


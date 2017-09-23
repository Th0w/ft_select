#include <unistd.h>

#include "ft_select.h"

#define FT_TERM ("TERM")
#define FT_NOENV ("Could not retrieve environment.\n")

# define FT_NOENV_CODE 1

void			print(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	write(1, str, len);
}

int				ft_error(const char *err_msg, const int err_code)
{
	size_t		len;
	len = 0;
	while (err_msg[len] != '\0')
		len++;
	write(2, err_msg, len);
	return (err_code);
}

int				main(int ac, char **av)
{
	int			i;
	t_clist		*args;
	char		*name;

	if ((name = getenv(FT_TERM)) == NULL)
		return (ft_error(FT_NOENV, FT_NOENV_CODE));
	print("term name: '");
	print(name);
	print("'\n");
	i = 1;
	args = NULL;
	while (i < ac)
	{
		ft_clist_append(&args, av[i]);
		i++;
	}
	return (0);
}

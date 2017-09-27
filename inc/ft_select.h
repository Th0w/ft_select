#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include <unistd.h> //
# include <stdio.h> //

# include "ft_mem.h"
# include "ft_clist.h"
# include "ft_btree.h"

# define FT_TERM ("TERM")
# define FT_NOENV ("Could not retrieve environment.\n")
# define FT_MEMALLOC ("Could not allocate memory.\n")

# define FT_NOENV_CODE 2
# define FT_MEMALLOC_CODE 3

# define FTK_UP 4283163
# define FTK_DOWN 4348699
# define FTK_RIGHT 4414235
# define FTK_LEFT 4479771
# define FTK_NL 10
# define FTK_ESC 27
# define FTK_SP 32
# define FTK_BRA 91
# define FTK_DEL 127

typedef void			(*t_keyptr)();

typedef struct termios	t_term;

typedef struct			s_ptr
{
	int					key;
	t_keyptr			ptr;
}						t_ptr;

typedef struct			s_env
{
	int					init;
	int					sigint;
	t_term				old;
}						t_env;

int						ft_intcmp(int lhs, int rhs);
int						ft_intptrcmp(void *lhs, void *rhs);

void					ft_sigexit(int signo);

int						ft_add_handlers(t_btree **handlers);

int						ft_change_term(t_term *new);
int						ft_restore_term(void);

int						ft_error(const char *err_msg, const int err_code);
int						ft_sel_exit(void);
t_env					*ft_sel_getenv(void);

void					ft_mv_up(void);
void 					ft_mv_down(void);
void 					ft_mv_right(void);
void 					ft_mv_left(void);
void 					ft_hand_return(void);
void 					ft_hand_cancel(void);
void 					ft_hand_space(void);

#endif

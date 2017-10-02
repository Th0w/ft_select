#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <curses.h>
# include <term.h>

# include <sys/ioctl.h>

# include "ft_mem.h"
# include "ft_clist.h"
# include "ft_btree.h"
# include "ft_string.h"

# include "ft_termcaps.h"

# define FT_TERM ("TERM")
# define FT_NOENV ("Could not retrieve environment.\n")
# define FT_EMEMALLOC ("Could not allocate memory.\n")
# define FT_EACT ("Could not create action trees.\n")
# define FT_ETERM ("Could not find corresponding term.\n")
# define FT_ETTY ("Error with current TTY of Standard Output FD\n")

# define FT_NOENV_CODE 2
# define FT_MEMALLOC_CODE 3

typedef void			(*t_keyptr)();

typedef struct termios	t_term;

typedef struct			s_ptr
{
	int					key;
	t_keyptr			ptr;
}						t_ptr;

typedef struct			s_arg
{
	char				*value;
	int					selected;
}						t_arg;

typedef struct			s_env
{
	int					init;
	size_t				widest;
	u_short				col;
	u_short				row;
	int					curr;
	int					arg_per_line;
	int					line_count;
	int					cnt;
	t_clist				*args;
	t_clist				*hovered;
	t_term				old;
	t_term				new;
	t_btree				*actions;
	t_btree				*handlers;
}						t_env;

int						ft_intcmp(int lhs, int rhs);
int						ft_intptrcmp(void *lhs, void *rhs);
int						ft_keycmp(void *lhs, void *rhs);

void					ft_sigexit(int signo);

int						ft_add_handlers(t_btree **handlers);
int						ft_add_actions(t_btree **handlers);

int						ft_change_term(t_term *new);
int						ft_restore_term(void);

int						ft_error(const char *err_msg, const int err_code);
int						ft_sel_exit(void);
t_env					*ft_sel_getenv(void);

void					ft_mv_up(void);
void 					ft_mv_down(void);
void 					ft_mv_right(void);
void 					ft_mv_left(void);
void					ft_handle_esc(char *buffer, t_env *env);
void					ft_handle_nl(char *buffer, t_env *env);
void 					ft_handle_sp(char *buffer, t_env *env);
void					ft_handle_del(char *buffer, t_env *env);

t_clist					*ft_clist_arg_to_list(int ac, char **av);
t_clist					*ft_clist_move(t_clist *list, int cnt);
char					*ft_clist_tostr_if(t_clist *list, int (*assert)());

void					ft_toggle_style(char *style);
void					ft_toggle_style_cnt(char *style, int cnt);
void					ft_move_cursor(int x, int y);
int						ft_get_cursor_pos(int *x, int *y);

void					ft_print_args(t_env *env);

int						ft_setup_env(int ac, char **av);
int						ft_toggle_term(int on);
int						ft_create_term(t_env *env);
void					ft_addsignal(void);

#endif

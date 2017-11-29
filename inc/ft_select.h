/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:47:21 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/29 22:46:28 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>
# include <fcntl.h>

# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/param.h>

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

enum					e_dir
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

enum					e_type
{
	REGU = 0,
	DIRE = 1,
	LINK = 2,
	ERRO = 4
};

enum					e_print
{
	DFLT = 1,
	HGHL = 2,
	SRCH = 4,
	SRCI = 8
};

typedef void			(*t_keyptr)();
typedef struct stat		t_stat;

typedef struct termios	t_term;

typedef struct			s_ptr
{
	int					key;
	t_keyptr			ptr;
}						t_ptr;

typedef struct			s_arg
{
	char				*value;
	enum e_type			type;
	int					selected;
	int					hidden;
}						t_arg;

typedef struct			s_env
{
	int					init;
	size_t				widest;
	u_short				col;
	u_short				row;
	int					curr;
	int					arg_per_line;
	void				(*printer)();
	int					cnt;
	t_clist				*args;
	t_clist				*hovered;
	t_term				old;
	t_term				new;
	t_btree				*actions;
	enum e_print		mode;
	int					fd;
	char				buf[MAXPATHLEN];
	int					buf_size;
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

void					ft_handle_buf(char buf[4], t_env *env);
void					ft_handle_esc(char buf[4], t_env *env);
void					ft_handle_nl(char buf[4], t_env *env);
void 					ft_handle_sp(char buf[4], t_env *env);
void					ft_handle_del(char buf[4], t_env *env);

void					ft_toggle_all(char buf[4], t_env *env);
void					ft_toggle_lnk(char buf[4], t_env *env);
void					ft_toggle_dir(char buf[4], t_env *env);
void					ft_toggle_non(char buf[4], t_env *env);
void					ft_toggle_fil(char buf[4], t_env *env);

void					ft_toggle_col(char buf[4], t_env *env);
void					ft_toggle_mode(t_env *env, char mode);

t_clist					*ft_clist_arg_to_list(int ac, char **av);
void					ft_clist_move(enum e_dir dir);
char					*ft_clist_tostr_if(t_clist *list, int (*assert)());
int						ft_clist_get_dist(t_clist *lhs, t_clist *rhs);

void					ft_toggle_style(char *style);
void					ft_toggle_style_cnt(char *style, int cnt);
void					ft_move_cursor(int x, int y);
int						ft_get_cursor_pos(int *x, int *y);

void					ft_print_args(t_env *env);

int						ft_setup_env(int ac, char **av);
int						ft_toggle_term(int on);
int						ft_create_term(t_env *env);
void					ft_addsignal(void);

int						ft_putfd0(int c);

void					ft_print_nopad(char *value, t_env *env, int hovered);
void					ft_print_shrink(char *value, t_env *env, int hovered);
void					ft_print_padded(char *value, t_env *env, int hovered);

int						ft_calcdim(t_env *env);
void					ft_setenv_dim(u_short *col, u_short *row);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:55:03 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/09 10:42:55 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

# define FT_STR_BLK ("                                ")
# define FT_STR_BLK_SZ 32

int			ft_atoi(const char *str);

long		ft_atol(const char *str);

int			ft_getnumber(char *str, char **newpos, int *nptr);

int			ft_iswhitespace(char c);
int			ft_isnum(char c);
int			ft_isnumeric(char c);

char		*ft_pathjoin(char *path, char *name);

void		ft_putstr_fd(char const *s, int fd);
void		ft_putstr(char const *s);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putendl(char const *s);

void		ft_putblank(size_t cnt);
void		ft_putblank_fd(size_t cnt, int fd);

int			ft_putchar(int c);

char		*ft_strcat(char *s1, const char *s2);

char		*ft_strchr(const char *s, int c);

void		ft_strclr(char *s);

int			ft_strcmp(const char *s1, const char *s2);

char		*ft_strcpy(char *dst, const char *src);

void		ft_strdel(char **as);

char		*ft_strdup(const char *s1);

int			ft_strequ(char const *s1, char const *s2);

int			ft_strindex(const char *str, const char c);

void		ft_striter(char *s, void (*f)(char *));

void		ft_striteri(char *s, void (*f)(unsigned int, char *));

char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinc(char const *s1, char const *s2, char const c);

size_t		ft_strlcat(char *dst, const char *src, size_t size);

size_t		ft_strlen(const char *s);

char		*ft_strmap(char const *s, char (*f)(char));

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char		*ft_strncat(char *s1, const char *s2, size_t n);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strncpy(char *dst, const char *src, size_t len);

int			ft_strnequ(char const *s1, char const *s2, size_t n);

char		*ft_strnew(size_t size);

char		*ft_strnstr(const char *big, const char *little, size_t len);

char		*ft_strrchr(const char *s, int c);

char		**ft_strsplit(char const *s, char c);

char		*ft_strstr(const char *big, const char *little);

char		*ft_strsub(char const *s, unsigned int start, size_t len);

void		ft_strptrcpy(char *buf, char const *beg, char const *end);
char		*ft_strtrim(char const *s);

void		ft_strforeach(char **arr, void (*action)());
void		ft_strforn(char **arr, size_t n, void (*action)());

void		ft_strforeach_data(char **arr, void (*action)(), void *data);
void		ft_strforn_data(char **arr, size_t n, void (*action)(), void *data);

size_t		ft_uintlen(u_int n);
size_t		ft_ulonglen(u_long n);

size_t		ft_intlen(int n);
size_t		ft_longlen(long n);

#endif

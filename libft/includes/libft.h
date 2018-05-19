/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoomany <agoomany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:36 by agoomany          #+#    #+#             */
/*   Updated: 2018/04/28 11:01:03 by agoomany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define GNL_BUFFSIZE 1024
# define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef int		t_bool;

char			**ft_add_in_darray(char **array, char *str);
int				ft_atoi(const char *str);
long int		ft_atol(const char *str);
void			ft_bzero(void *s, size_t n);
void			ft_free_darray(char **array);
int				ft_isalldigit(char *str);
int				ft_ishex(char *str);
char			*ft_itoa(int n);
char			*ft_ltoa(long long n);
char			*ft_merge_array(char **array, int i, char *sep);
void			ft_print_darray(char **array);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_size_darray(char **array);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2, int free_m);
char			*ft_strjoin_sep(char const *s1, char const *s2, char const sep);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
int				get_next_line(int const fd, char **line);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strnew(size_t size);
char			*ft_strcat(char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strndup(const char *s1, size_t n);
char			**ft_strsplit_trim(char const *s, char c);
int				ft_isalldigit_sign(char *str);
int				ft_isdigitpoint(char *str);

#endif

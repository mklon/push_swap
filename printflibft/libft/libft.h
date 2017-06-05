/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:26:39 by oposhiva          #+#    #+#             */
/*   Updated: 2017/03/01 13:42:55 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *destination, const void *source, size_t n);
void				*ft_memccpy (void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *source, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *destination, const char *source);
char				*ft_strncpy(char *dst, const char *source, size_t n);
char				*ft_strcat(char *destination, const char *append);
char				*ft_strncat(char *dst, const char *append, size_t n);
size_t				ft_strlcat(char *dst, const char *source, size_t size);
char				*ft_strchr(const char *source, int ch);
char				*ft_strrchr(const char *source, int ch);
char				*ft_strstr(const char *str_b, const char *str_a);
char				*ft_strnstr(const char *big, const char *lit, size_t len);
int					ft_strcmp(const char *str1, const char *str2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
long int			ft_atoi(const char *str);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnchr(char c, int n);
void				ft_putnstr(char const *s, int n);
void				ft_putnbr(long long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_vig_coder(char *text, char *pass);
char				*ft_vig_decoder(char *text, char *pass);
char				*ft_strrev(char *str);
int					ft_abs(int n);
int					ft_max_div(int a, int b);
unsigned int		ft_numlen(long long int num);
unsigned int		ft_numulen(unsigned long long int num);
int					ft_power(int num, int pow);
void				ft_putunbr(unsigned long long int n);
void				ft_swap(int *first, int *second);

#endif

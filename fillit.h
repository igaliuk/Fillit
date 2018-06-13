/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:58:21 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/10 16:48:02 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_data
{
	size_t			lenmap;
	int				size;
	int				count;
	char			c;
}					t_data;

void				law(int	*arrtet, int x, int y);
int					checknewfig(int *arrtet, char *strsquere,
	t_data *data, t_xy current);
void				writefig(int *arrtet, char *strsquere, t_data *data);
void				erasefig(char *strsquere, char c);
int					fillit(int **arrmap, t_data *data, char *strsquere);

int					ft_checkmapsize(char *dst, int x, int y);
int					ft_checkmapchar(char *dst, char *src);
int					checkmapfour(char *dst, char c);

void				arronetet(char *dst, char c, int *arrtet);
int					checktouch(char *dst, char c, int *arrtet);
int					startchecks(char *dst, int *arrtet);

int					binarytet(int *arrtet, size_t st);
int					binaryarr(int **arrmap, size_t lenmap);

void				adddel(char **strsquere, int **arrmap,
	size_t lenmap, int size);
void				blanksquere(char *strsquere, int size);
int					sizesquere(int **arrmap, size_t lenmap);
void				squere(int **arrmap, size_t lenmap);

void				arrallxy(t_list *lstmap, int **arrmap, size_t lenmap);
void				erexit(int fd);
t_list				*readmap(char *dst);

size_t				ft_lstlen(t_list **alst);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				del(void *mem, size_t content_size);
size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
void				ft_putstr(char const *s);
void				ft_strdel(char **ap);
void				ft_arrdel(int **arr, size_t	len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:24:00 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:24:02 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	arrallxy(t_list *lstmap, int **arrmap, size_t lenmap)
{
	t_list	*lsttmp;
	size_t	i;

	lsttmp = lstmap;
	i = 0;
	while (lsttmp != 0)
	{
		arrmap[i] = (int *)(malloc(sizeof(int) * 8));
		if (arrmap[i] == NULL)
		{
			ft_arrdel(arrmap, lenmap);
			exit(0);
		}
		if (startchecks(lsttmp->content, arrmap[i]) == 0)
		{
			write(1, "error\n", 6);
			exit(0);
		}
		i++;
		lsttmp = lsttmp->next;
	}
}

void	erexit(int fd)
{
	close(fd);
	write(1, "error\n", 6);
	exit(0);
}

t_list	*readmap(char *dst)
{
	int		fd;
	int		ret;
	char	buf[21];
	t_list	*lsttmp;
	t_list	*lstbegin;

	fd = open(dst, O_RDONLY);
	ret = read(fd, buf, 21);
	if (ret < 20)
		erexit(fd);
	buf[20] = '\0';
	lsttmp = ft_lstnew(buf, ret);
	lstbegin = lsttmp;
	while (ret == 21)
	{
		ret = read(fd, buf, 21);
		if (ret < 20)
			erexit(fd);
		buf[20] = '\0';
		lsttmp->next = ft_lstnew(buf, 21);
		lsttmp = lsttmp->next;
	}
	close(fd);
	return (lstbegin);
}

int		main(int argc, char **argv)
{
	t_list	*lstmap;
	int		**arrmap;
	size_t	lenmap;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		exit(0);
	}
	lstmap = readmap(argv[1]);
	lenmap = ft_lstlen(&lstmap);
	if ((lenmap == 0) || (lenmap > 26))
	{
		write(1, "error\n", 6);
		exit(0);
	}
	arrmap = (int **)(malloc(sizeof(int *) * lenmap));
	if (arrmap == NULL)
		exit(0);
	arrallxy(lstmap, arrmap, lenmap);
	ft_lstdel(&lstmap, del);
	squere(arrmap, lenmap);
	return (0);
}

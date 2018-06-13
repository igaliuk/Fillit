/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:36:53 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/03 18:36:55 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if ((alst != 0) && (del != 0))
	{
		while (*alst != 0)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = NULL;
		}
	}
}

void	del(void *mem, size_t content_size)
{
	free(mem);
	mem = NULL;
	content_size = 0;
}

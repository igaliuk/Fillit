/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:59:09 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/04 18:59:25 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_checkmapsize(char *dst, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i] != '\0')
	{
		j = 0;
		while (dst[i + j] != '\n')
			j++;
		if (j != x)
			return (0);
		i = i + j + 1;
		y--;
	}
	if (y != 0)
		return (0);
	return (1);
}

int	ft_checkmapchar(char *dst, char *src)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	while (dst[i] != '\0')
	{
		b = 0;
		j = 0;
		while (src[j] != '\0')
		{
			if ((dst[i] == src[j]) || (dst[i] == '\n'))
				b = 1;
			j++;
		}
		if (b == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checkmapfour(char *dst, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (dst[i])
		if (dst[i++] == c)
			k++;
	if (k == 4)
		return (1);
	return (0);
}

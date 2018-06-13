/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startchecks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:28:15 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:28:17 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	arronetet(char *dst, char c, int *arrtet)
{
	int	i;
	int	j;
	int k;

	k = 0;
	j = 0;
	while (dst[j] != '\0')
	{
		i = 0;
		while (dst[j + i] != '\n')
		{
			if (dst[j + i] == c)
			{
				arrtet[k++] = i;
				arrtet[k++] = j / 5;
			}
			i++;
		}
		j = j + i + 1;
	}
}

int		checktouch(char *dst, char c, int *arrtet)
{
	int i;
	int k;
	int	t;

	t = 0;
	i = 0;
	while (i < 8)
	{
		k = arrtet[i] + arrtet[i + 1] * 5;
		if ((arrtet[i] != 3) && (dst[k + 1] == c))
			t++;
		if ((arrtet[i] != 0) && (dst[k - 1] == c))
			t++;
		if ((arrtet[i + 1] != 3) && (dst[k + 5] == c))
			t++;
		if ((arrtet[i + 1] != 0) && (dst[k - 5] == c))
			t++;
		i = i + 2;
	}
	if ((t == 6) || (t == 8))
		return (1);
	return (0);
}

int		startchecks(char *dst, int *arrtet)
{
	if ((ft_checkmapchar(dst, "#.") == 1) && (ft_checkmapsize(dst, 4, 4) == 1)
		&& (checkmapfour(dst, '#') == 1))
	{
		arronetet(dst, '#', arrtet);
		if (checktouch(dst, '#', arrtet) == 1)
			return (1);
	}
	return (0);
}

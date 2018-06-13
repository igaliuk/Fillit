/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:27:16 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:27:17 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		binarytet(int *arrtet, size_t st)
{
	size_t	i;
	size_t	j;
	int		r;

	r = 0;
	j = st;
	while (j < 8)
	{
		i = st;
		while (i < j)
		{
			if (arrtet[i] != arrtet[j])
				r++;
			i = i + 2;
		}
		j = j + 2;
	}
	if ((r % 2) == 0)
		return (1);
	return (0);
}

int		binaryarr(int **arrmap, size_t lenmap)
{
	size_t	i;
	t_xy	xy;

	xy.x = 0;
	xy.y = 0;
	i = 0;
	while (i < lenmap)
	{
		if (binarytet(arrmap[i], 0) == 1)
			xy.x++;
		if (binarytet(arrmap[i], 1) == 1)
			xy.y++;
		i++;
	}
	if ((xy.x == (int)lenmap) && (xy.y == (int)lenmap))
		return (1);
	return (0);
}

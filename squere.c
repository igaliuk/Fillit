/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:24:13 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:24:15 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	adddel(char **strsquere, int **arrmap, size_t lenmap, int size)
{
	*strsquere = (char *)malloc(sizeof(char) * (size * (size + 1) + 1));
	if (*strsquere == NULL)
	{
		ft_arrdel(arrmap, lenmap);
		exit(0);
	}
}

void	blanksquere(char *strsquere, int size)
{
	int	i;

	i = 0;
	while (i < size * (size + 1))
	{
		strsquere[i] = '.';
		if ((i == size) || (((i + 1) % (size + 1)) == 0))
			strsquere[i] = '\n';
		i++;
	}
	strsquere[i] = '\0';
}

int		sizesquere(int **arrmap, size_t lenmap)
{
	int	size;

	size = 2;
	while (((size * size) / 4) < (int)lenmap)
		size++;
	if ((binaryarr(arrmap, lenmap) == 1) && ((size % 2) != 0))
		return (((size / 2) + 1) * 2);
	return (size);
}

void	squere(int **arrmap, size_t lenmap)
{
	char	*strsquere;
	t_data	data;
	int		k;

	data.size = sizesquere(arrmap, lenmap);
	k = 1;
	while (k == 1)
	{
		k = 0;
		adddel(&strsquere, arrmap, lenmap, data.size);
		blanksquere(strsquere, data.size);
		data.lenmap = lenmap;
		data.count = 0;
		data.c = 'A';
		if (fillit(arrmap, &data, strsquere) == 0)
		{
			ft_strdel(&strsquere);
			data.size++;
			k = 1;
		}
	}
	ft_putstr(strsquere);
	ft_arrdel(arrmap, lenmap);
	ft_strdel(&strsquere);
}

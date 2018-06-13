/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 10:27:31 by igaliuk           #+#    #+#             */
/*   Updated: 2017/11/18 10:27:33 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	law(int *arrtet, int x, int y)
{
	int i;

	x = x - arrtet[0];
	y = y - arrtet[1];
	i = 0;
	while (i < 8)
	{
		arrtet[i] = arrtet[i] + x;
		arrtet[i + 1] = arrtet[i + 1] + y;
		i = i + 2;
	}
}

int		checknewfig(int *arrtet, char *strsquere, t_data *data, t_xy current)
{
	int	i;
	int	k;

	law(arrtet, current.x, current.y);
	i = 0;
	while (i < 8)
	{
		k = arrtet[i] + arrtet[i + 1] * (data->size + 1);
		if ((arrtet[i] >= data->size) || (arrtet[i + 1] >= data->size)
			|| (strsquere[k] != '.'))
			return (0);
		i = i + 2;
	}
	return (1);
}

void	writefig(int *arrtet, char *strsquere, t_data *data)
{
	int	i;
	int	k;

	i = 0;
	while (i < 8)
	{
		k = arrtet[i] + arrtet[i + 1] * (data->size + 1);
		strsquere[k] = data->c;
		i = i + 2;
	}
}

void	erasefig(char *strsquere, char c)
{
	int	i;

	i = 0;
	while (strsquere[i] != 0)
	{
		if (strsquere[i] == c)
			strsquere[i] = '.';
		i++;
	}
}

int		fillit(int **arrmap, t_data *data, char *strsquere)
{
	t_xy current;

	if (data->count == (int)data->lenmap)
		return (1);
	current.y = 0;
	while (current.y < data->size)
	{
		current.x = 0;
		while (current.x < data->size)
		{
			if (checknewfig(arrmap[data->count], strsquere, data, current) == 1)
			{
				writefig(arrmap[data->count++], strsquere, data);
				data->c++;
				fillit(arrmap, data, strsquere);
				if (data->count == (int)data->lenmap)
					return (1);
			}
			current.x++;
		}
		current.y++;
	}
	data->count--;
	erasefig(strsquere, --data->c);
	return (0);
}

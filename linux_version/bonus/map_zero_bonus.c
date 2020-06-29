/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2merde.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:42:25 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 18:24:07 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		poswitch(t_move *mv, int i, int j)
{
	if (mv->map[i - 1][j - 1] == ' ')
		return (0);
	else if (mv->map[i - 1][j] == ' ')
		return (0);
	else if (mv->map[i - 1][j + 1] == ' ')
		return (0);
	else if (mv->map[i][j - 1] == ' ')
		return (0);
	else if (mv->map[i][j + 1] == ' ')
		return (0);
	else if (mv->map[i + 1][j - 1] == ' ')
		return (0);
	else if (mv->map[i + 1][j] == ' ')
		return (0);
	else if (mv->map[i + 1][j + 1] == ' ')
		return (0);
	else
		return (1);
}

int		checkentour(t_move *mv)
{
	int		i;
	int		j;

	i = 1;
	if (!poswitch(mv, (int)mv->posy, (int)mv->posx))
		return (0);
	while (mv->map[i + 1])
	{
		j = 1;
		while (mv->map[i][j + 1])
		{
			if (mv->map[i][j] == '0' || mv->map[i][j] == '2')
			{
				if (!(poswitch(mv, i, j)))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

char	*newline(char *oldline, int maxx)
{
	int		i;
	char	*nwline;

	i = 0;
	if (!(nwline = malloc(maxx + 1)))
		return (NULL);
	while (oldline[i])
	{
		nwline[i] = oldline[i];
		i++;
	}
	while (i < maxx)
		nwline[i++] = ' ';
	nwline[i] = 0;
	free(oldline);
	return (nwline);
}

int		newmap(t_index *idx, t_move *mv, int fd)
{
	int		maxy;
	size_t	maxx;

	mv->maxy = 0;
	maxx = 0;
	if (!(storemap(fd, idx)))
		return (0);
	while (mv->map[mv->maxy])
	{
		if (ft_strlen(mv->map[mv->maxy]) > maxx)
			maxx = ft_strlen(mv->map[mv->maxy]);
		mv->maxy++;
	}
	maxy = 0;
	while (mv->map[maxy])
	{
		if (ft_strlen(mv->map[maxy]) < maxx)
		{
			if (!(mv->map[maxy] = newline(mv->map[maxy], maxx)))
				return (0);
		}
		maxy++;
	}
	return (checkentour(mv));
}

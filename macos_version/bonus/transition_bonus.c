/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:02:17 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 14:55:40 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	maxres(t_index *idx)
{
	if (idx->w > 2560)
		idx->w = 2560;
	if (idx->h > 1440)
		idx->h = 1440;
}

int		dirtostruct(t_index *idx, t_move *mv)
{
	if (idx->dir == 'S' || idx->dir == 'N')
	{
		mv->dirx = 0;
		mv->diry = 1;
		mv->planex = -0.66;
		mv->planey = 0;
		if (idx->dir == 'N')
		{
			mv->diry = -1.0;
			mv->planex = 0.66;
		}
	}
	else if (idx->dir == 'W' || idx->dir == 'E')
	{
		mv->dirx = -1;
		mv->diry = 0;
		mv->planex = 0;
		mv->planey = -0.66;
		if (idx->dir == 'E')
		{
			mv->dirx = 1.0;
			mv->planey = 0.66;
		}
	}
	return (1);
}

int		smaptostruct(t_index *idx, t_sprite *sp)
{
	int		i;
	int		j;

	i = 0;
	sp->num = 0;
	while (idx->mv->map[i] != NULL)
	{
		j = 0;
		while (idx->mv->map[i][j++] != '\0')
		{
			if (idx->mv->map[i][j] == '2')
				sp->num++;
		}
		i++;
	}
	if (!(sp->smapx = malloc(sizeof(float) * sp->num)) || \
			!(sp->smapy = malloc(sizeof(float) * sp->num)))
	{
		write(1, "Error\nImage failed4\n", 20);
		return (s_free(idx));
	}
	return (dirtostruct(idx, idx->mv));
}

int		parstostruct(t_index *idx, t_move *mv)
{
	int		i;
	int		j;

	i = 0;
	if (!(smaptostruct(idx, idx->sp)))
		return (0);
	idx->sp->num = 0;
	while (mv->map[i] != NULL)
	{
		j = 0;
		while (mv->map[i][j] != '\0')
		{
			if (mv->map[i][j++] == '2')
			{
				idx->sp->smapx[idx->sp->num] = (float)j - 0.5;
				idx->sp->smapy[idx->sp->num] = (float)i + 0.5;
				idx->sp->num++;
			}
		}
		i++;
	}
	mv->map[(int)mv->posy][(int)mv->posx] = '0';
	return (1);
}

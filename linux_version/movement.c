/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:49:57 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 15:18:33 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_input(int key, t_move *mv)
{
	if (key == 119)
	{
		if (mv->map[(int)mv->posy][(int)(mv->posx + mv->dirx * 0.5)] != '1')
			mv->posx += mv->dirx * 0.4;
		if (mv->map[(int)(mv->posy + mv->diry * 0.5)][(int)mv->posx] != '1')
			mv->posy += mv->diry * 0.4;
	}
	else if (key == 115)
	{
		if (mv->map[(int)mv->posy][(int)(mv->posx - mv->dirx * 0.5)] != '1')
			mv->posx -= mv->dirx * 0.4;
		if (mv->map[(int)(mv->posy - mv->diry * 0.5)][(int)mv->posx] != '1')
			mv->posy -= mv->diry * 0.4;
	}
	else if (key == 97 || key == 100)
		strife(key, mv);
	else if (key == 65363 || key == 65361)
		rotation(key, mv);
	else if (key == 65307)
		freexit(mv->idx, 2);
	mlx_clear_window(mv->idx->ptr, mv->idx->win);
	raycast_loop(mv->idx, mv->idx->alg, mv);
	return (0);
}

void	strife(int key, t_move *mv)
{
	if (key == 100)
	{
		if (mv->map[(int)(mv->posy + mv->dirx * 0.5)][(int)mv->posx] != '1')
			mv->posy += mv->dirx * 0.4;
		if (mv->map[(int)mv->posy][(int)(mv->posx - mv->diry * 0.5)] != '1')
			mv->posx -= mv->diry * 0.4;
	}
	else if (key == 97)
	{
		if (mv->map[(int)(mv->posy - mv->dirx * 0.5)][(int)mv->posx] != '1')
			mv->posy -= mv->dirx * 0.4;
		if (mv->map[(int)mv->posy][(int)(mv->posx + mv->diry * 0.5)] != '1')
			mv->posx += mv->diry * 0.4;
	}
}

void	rotation(int key, t_move *mv)
{
	float	rots;
	float	oldirx;
	float	oldplanex;

	rots = 0.2;
	if (key == 65361)
	{
		oldirx = mv->dirx;
		mv->dirx = mv->dirx * cos(-rots) - mv->diry * sin(-rots);
		mv->diry = oldirx * sin(-rots) + mv->diry * cos(-rots);
		oldplanex = mv->planex;
		mv->planex = mv->planex * cos(-rots) - mv->planey * sin(-rots);
		mv->planey = oldplanex * sin(-rots) + mv->planey * cos(-rots);
	}
	else if (key == 65363)
	{
		oldirx = mv->dirx;
		mv->dirx = mv->dirx * cos(rots) - mv->diry * sin(rots);
		mv->diry = oldirx * sin(rots) + mv->diry * cos(rots);
		oldplanex = mv->planex;
		mv->planex = mv->planex * cos(rots) - mv->planey * sin(rots);
		mv->planey = oldplanex * sin(rots) + mv->planey * cos(rots);
	}
}

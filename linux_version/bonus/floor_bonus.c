/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:01:23 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 15:11:17 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_cell(t_index *idx, t_floor *fl, t_cell *cl, int y)
{
	int	x;
	int	*floor;
	int *ceil;
	int *dst;

	x = 0;
	floor = (int *)fl->addr;
	ceil = (int *)cl->addr;
	dst = (int *)idx->wall->addr;
	while (x < idx->w)
	{
		cl->cellx = (int)(fl->floorx);
		cl->celly = (int)(fl->floory);
		cl->tx = (int)(cl->width * (fl->floorx - cl->cellx)) & (cl->width - 1);
		cl->ty = (int)(cl->height * (fl->floory - \
					cl->celly)) & (cl->height - 1);
		fl->floorx += fl->fstepx;
		fl->floory += fl->fstepy;
		dst[y * idx->w + x] =
			shade_color(floor[fl->width * cl->ty + cl->tx], fl->rowdist);
		dst[(idx->h * idx->w) - (idx->w * y) - idx->w + x] =
			shade_color(ceil[fl->width * cl->ty + cl->tx], fl->rowdist);
		x++;
	}
}

void	draw_floor(t_index *idx, t_move *mv, t_floor *fl, t_cell *cl)
{
	int y;

	y = 0;
	while (y < idx->h)
	{
		fl->raydirfx = mv->dirx - mv->planex;
		fl->raydirfy = mv->diry - mv->planey;
		fl->raydircx = mv->dirx + mv->planex;
		fl->raydircy = mv->diry + mv->planey;
		fl->p = y - (idx->h >> 1);
		fl->posz = 0.5 * idx->h;
		fl->rowdist = fl->posz / fl->p;
		fl->fstepx = fl->rowdist * (fl->raydircx - fl->raydirfx) / idx->w;
		fl->fstepy = fl->rowdist * (fl->raydircy - fl->raydirfy) / idx->w;
		fl->floorx = mv->posx + fl->rowdist * fl->raydirfx;
		fl->floory = mv->posy + fl->rowdist * fl->raydirfy;
		draw_cell(idx, fl, cl, y);
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:31:18 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 18:13:46 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_y(t_index *idx, int spheight, int texx, int stripe)
{
	int		texy;
	int		y;
	int		d;
	int		*sprite;
	int		*dst;

	sprite = (int *)idx->sp->addr;
	dst = (int *)idx->wall->addr;
	y = idx->sp->drawsy;
	texy = 1;
	while (y <= idx->sp->drawey)
	{
		d = (y) * 256 - idx->h * 128 + spheight * 128;
		texy = ((d * 64) / spheight) / 256;
		if (texy < 64 && (sprite[texy * 64 + texx] & 0x00FFFFFF))
			dst[y * idx->w + stripe] = 
			shade_color(sprite[texy * 64 + texx], idx->sp->zbuffer[stripe]);
		y++;
	}
}

void	sp_draw(t_index *idx, int spheight, int spwidth, int spscreenx)
{
	int		stripe;
	int		texx;

	stripe = idx->sp->drawsx;
	while (stripe < idx->sp->drawex)
	{
		texx = (int)((stripe - (-spwidth / 2 + spscreenx)) * \
				64 / spwidth);
		if (idx->sp->trsformy > 0 && stripe > 0 && stripe < idx->w && \
				idx->sp->trsformy < idx->sp->zbuffer[stripe] && texx < 64)
		{
			sprite_y(idx, spheight, texx, stripe);
		}
		stripe++;
	}
}

void	dimension(t_index *idx, t_sprite *sp, int spscreenx)
{
	int		spheight;
	int		spwidth;

	spheight = (int)fabs((float)idx->h / sp->trsformy);
	sp->drawsy = -spheight / 2 + idx->h / 2;
	if (sp->drawsy < 0)
		sp->drawsy = 0;
	sp->drawey = spheight / 2 + idx->h / 2;
	if (sp->drawey >= idx->h)
		sp->drawey = idx->h - 1;
	spwidth = (int)fabs((float)idx->h / sp->trsformy);
	sp->drawsx = -spwidth / 2 + spscreenx;
	if (sp->drawsx < 0)
		sp->drawsx = 0;
	sp->drawex = spwidth / 2 + spscreenx;
	if (sp->drawex >= idx->h)
		sp->drawex = idx->w - 1;
	sp_draw(idx, spheight, spwidth, spscreenx);
}

void	sprite_sort(t_move *mv, t_sprite *sp)
{
	int		i;
	int		j;
	float	spdist;

	i = 0;
	while (i < sp->num - 1)
	{
		spdist = ((mv->posx - sp->smapx[i]) * (mv->posx - sp->smapx[i]) + \
				(mv->posy - sp->smapy[i]) * (mv->posy - sp->smapy[i]));
		j = i + 1;
		while (j < sp->num)
		{
			if (((mv->posx - sp->smapx[j]) * (mv->posx - sp->smapx[j]) + \
				(mv->posy - sp->smapy[j]) * (mv->posy - sp->smapy[j])) > spdist)
			{
				spdist = ((mv->posx - sp->smapx[j]) * \
						(mv->posx - sp->smapx[j]) + (mv->posy - sp->smapy[j]) \
						* (mv->posy - sp->smapy[j]));
				ft_swap(sp, i, j, 'x');
				ft_swap(sp, i, j, 'y');
			}
			j++;
		}
		i++;
	}
}

void	sprite(t_index *idx, t_move *mv, t_sprite *sp)
{
	float	spritex;
	float	spritey;
	float	invdet;
	int		spscreenx;
	int		i;

	i = 0;
	sprite_sort(mv, sp);
	while (i < sp->num)
	{
		spritex = sp->smapx[i] - mv->posx;
		spritey = sp->smapy[i] - mv->posy;
		invdet = 1.0 / (mv->planex * mv->diry - mv->dirx * mv->planey);
		sp->trsformx = invdet * (mv->diry * spritex - mv->dirx * spritey);
		sp->trsformy = invdet * (-mv->planey * spritex + mv->planex * spritey);
		spscreenx = (int)((idx->w / 2) * (1 + sp->trsformx / sp->trsformy));
		dimension(idx, sp, spscreenx);
		i++;
	}
}

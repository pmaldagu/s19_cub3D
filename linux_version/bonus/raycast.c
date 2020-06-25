/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:15:17 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 20:58:31 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ray_side(t_algo *alg, t_move *mv, t_text *text, int side)
{
	if (side == 1)
	{
		if (alg->mapy < mv->posy)
			text->wall = 0;
		else
			text->wall = 1;
		text->wallx = mv->posx + alg->perpwdist * alg->raydirx;
		text->wallx -= floor(text->wallx);
		text->texx = (int)(text->wallx * (float)text->width);
		if (alg->raydiry < 0)
			text->texx = text->width - text->texx - 1;
	}
	else
	{
		if (alg->mapx < mv->posx)
			text->wall = 2;
		else
			text->wall = 3;
		text->wallx = mv->posy + alg->perpwdist * alg->raydiry;
		text->wallx -= floor(text->wallx);
		text->texx = (int)(text->wallx * (float)text->width);
		if (alg->raydirx > 0)
			text->texx = text->width - text->texx - 1;
	}
}

void	ray_draw(t_index *idx, t_algo *alg, int x, int side)
{
	int		lineh;

	if (side == 0)
		alg->perpwdist = (alg->mapx - idx->mv->posx + \
				((1 - alg->stepx) >> 1)) / alg->raydirx;
	else
		alg->perpwdist = (alg->mapy - idx->mv->posy + \
				((1 - alg->stepy) >> 1)) / alg->raydiry;
	if (alg->perpwdist == 0)
		alg->perpwdist = 0.1;
	lineh = (int)(idx->h / alg->perpwdist);
	alg->drstart = (-lineh >> 1) + (idx->h >> 1);
	if (alg->drstart < 0)
		alg->drstart = 0;
	alg->drend = (lineh >> 1) + (idx->h >> 1);
	if (alg->drend >= idx->h)
		alg->drend = idx->h - 1;
	idx->text->step = 1.0 * 64 / lineh;
	idx->text->textpos = (alg->drstart - (idx->h >> 1) + (lineh >> 1)) * \
						idx->text->step;
	idx->sp->zbuffer[x] = alg->perpwdist;
}

int		ray_dda(t_index *idx, t_algo *alg)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (alg->sidedistx < alg->sidedisty)
		{
			alg->sidedistx += alg->deltadistx;
			alg->mapx += alg->stepx;
			side = 0;
		}
		else
		{
			alg->sidedisty += alg->deltadisty;
			alg->mapy += alg->stepy;
			side = 1;
		}
		if (idx->mv->map[alg->mapy][alg->mapx] == '1')
			hit = 1;
	}
	return (side);
}

void	ray_step(t_algo *alg, t_move *mv)
{
	if (alg->raydirx < 0)
	{
		alg->stepx = -1;
		alg->sidedistx = (mv->posx - alg->mapx) * alg->deltadistx;
	}
	else
	{
		alg->stepx = 1;
		alg->sidedistx = (alg->mapx + 1.0 - mv->posx) * alg->deltadistx;
	}
	if (alg->raydiry < 0)
	{
		alg->stepy = -1;
		alg->sidedisty = (mv->posy - alg->mapy) * alg->deltadisty;
	}
	else
	{
		alg->stepy = 1;
		alg->sidedisty = (alg->mapy + 1.0 - mv->posy) * alg->deltadisty;
	}
}

void	raycast_loop(t_index *idx, t_algo *alg, t_move *mv)
{
	int		x;
	int		side;
	float	camerax;

	x = 0;
	draw_floor(idx, mv, idx->fl, idx->cl);
	while (x < idx->w)
	{
		camerax = 2.0 * x / (float)idx->w - 1;
		alg->raydirx = mv->dirx + mv->planex * camerax;
		alg->raydiry = mv->diry + mv->planey * camerax;
		alg->mapx = (int)mv->posx;
		alg->mapy = (int)mv->posy;
		alg->deltadistx = fabs(1 / alg->raydirx);
		alg->deltadisty = fabs(1 / alg->raydiry);
		ray_step(alg, mv);
		side = ray_dda(idx, alg);
		ray_draw(idx, alg, x, side);
		ray_side(alg, mv, idx->text, side);
		draw_column(idx, alg, x);
		x++;
	}
	sprite(idx, mv, idx->sp);
	if (idx->win)
		mlx_put_image_to_window(idx->ptr, idx->win, idx->wall->img, 0, 0);
}

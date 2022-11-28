/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:20:43 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/05 19:33:23 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_column(t_index *idx, t_algo *alg, int x)
{
	int y;
	int *dst;
	int *text;
	int texy;

	y = 0;
	dst = (int *)idx->wall->addr;
	text = (int *)idx->text->addr[idx->text->wall];
	while (y < alg->drstart)
	{
		dst[y * idx->w + x] = idx->c;
		y++;
	}
	while (y <= alg->drend)
	{
		texy = (int)idx->text->textpos & (TXT_HW - 1);
		idx->text->textpos += idx->text->step;
		dst[y * idx->w + x] = text[texy * TXT_HW + idx->text->texx];
		y++;
	}
	while (y < idx->h)
	{
		dst[y * idx->w + x] = idx->f;
		y++;
	}
}

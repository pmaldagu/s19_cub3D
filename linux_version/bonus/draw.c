/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:20:43 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 14:41:28 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	shade_color(int color, float distance) //divide = distance / 1.5
{
	float divide;

	divide = distance / 1.5;
	if (divide <= 1.0)
		return (color);
	color = ((int)(((0xFF0000 & color) >> 16) / divide) << 16) +
	((int)(((0x00FF00 & color) >> 8) / divide) << 8) + 
	((int)((0x0000FF & color) / divide));
	return color;
}

void	draw_column(t_index *idx, t_algo *alg, int x)
{
	int y;
	int *dst;
	int *text;
	int texy;

	y = 0;
	dst = (int *)idx->wall->addr;
	text = (int *)idx->text->addr[idx->text->wall];
	y = alg->drstart;
	while (y <= alg->drend)
	{
		texy = (int)idx->text->textpos & (TXT_HW - 1);
		idx->text->textpos += idx->text->step;
		dst[y * idx->w + x] = 
			shade_color(text[texy * TXT_HW + idx->text->texx],
			 alg->perpwdist);
		y++;
	}
}

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
		dst[y * idx->w + x] = text[texy * TXT_HW + idx->text->texx];
		y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:56:53 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 18:50:59 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initptr(t_index *idx)
{
	int i;

	i = 0;
	idx->mv->map = NULL;
	while (i < 4)
	{
		idx->text->img[i] = NULL;
		idx->text->addr[i] = NULL;
		idx->text->path[i] = NULL;
		i++;
	}
	idx->wall->img = NULL;
	idx->wall->addr = NULL;
	idx->sp->smapx = NULL;
	idx->sp->smapy = NULL;
	idx->sp->path = NULL;
	idx->sp->img = NULL;
	idx->sp->addr = NULL;
	idx->sp->zbuffer = NULL;
}

void	freemap(t_move *mv, t_text *text)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (text->img[i] != NULL)
			mlx_destroy_image(mv->idx->ptr, text->img[i]);
		free(text->path[i]);
		text->img[i] = NULL;
		text->path[i] = NULL;
		i++;
	}
	i = 0;
	while (i < mv->maxy)
	{
		free(mv->map[i]);
		mv->map[i] = NULL;
		i++;
	}
	mv->map = NULL;
}

void	freeimg(t_index *idx, t_sprite *sp, t_img *wall)
{
	int i;

	i = 0;
	if (sp->img != NULL)
		mlx_destroy_image(idx->ptr, sp->img);
	sp->img = NULL;
	if (wall->img != NULL)
		mlx_destroy_image(idx->ptr, wall->img);
	wall->img = NULL;
	free(sp->path);
	sp->path = NULL;
	i = 0;
	free(sp->zbuffer);
	sp->zbuffer = NULL;
	free(sp->smapx);
	free(sp->smapy);
	sp->smapx = NULL;
	sp->smapy = NULL;
	freemap(idx->mv, idx->text);
}

void	freestruct(t_index *idx)
{
	free(idx->alg);
	free(idx->mv);
	free(idx->wall);
	free(idx->text);
	idx->alg = NULL;
	idx->mv = NULL;
	idx->wall = NULL;
	idx->text = NULL;
	idx->sp = NULL;
}

int		freexit(t_index *idx, int err)
{
	if (err == 0)
	{
		write(1, "Error\nMalloc failed\n", 19);
		freestruct(idx);
	}
	else if (err == 1)
	{
		freeimg(idx, idx->sp, idx->wall);
		freestruct(idx);
	}
	else if (err == 2)
	{
		mlx_clear_window(idx->ptr, idx->win);
		freeimg(idx, idx->sp, idx->wall);
		freestruct(idx);
		mlx_destroy_window(idx->ptr, idx->win);
		exit(0);
	}
	return (0);
}

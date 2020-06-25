/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:20:43 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 15:09:15 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	bonusinit(t_index *idx)
{
	char	*flpath;
	char	*clpath;

	flpath = "./bonus/textures/sol.xpm";
	clpath = "./bonus/textures/sky.xpm";
	idx->fl = NULL;
	idx->cl = NULL;
	if (!(idx->fl = malloc(sizeof(t_floor))))
		return (freexit(idx, 1));
	else if (!(idx->cl = malloc(sizeof(t_cell))))
		return (freexit(idx, 1));
	idx->fl->img = NULL;
	idx->cl->img = NULL;
	if (!(idx->fl->img = mlx_xpm_file_to_image(idx->ptr, flpath, \
					&idx->fl->width, &idx->fl->height)))
		return (freexit(idx, 1));
	else if (!(idx->cl->img = mlx_xpm_file_to_image(idx->ptr, clpath, \
					&idx->cl->width, &idx->cl->height)))
		return (freexit(idx, 1));
	idx->fl->addr = mlx_get_data_addr(idx->fl->img, &idx->fl->bits_per_pixel, \
			&idx->fl->line_length, &idx->fl->endian);
	idx->cl->addr = mlx_get_data_addr(idx->cl->img, &idx->cl->bits_per_pixel, \
			&idx->cl->line_length, &idx->cl->endian);
	return (1);
}

int	key_exit(t_index *idx)
{
	freexit(idx, 2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_index		idx;
	t_sprite	sp;

	idx.sp = &sp;
	if (!(idx.ptr = mlx_init()))
		return (EXIT_FAILURE);
	if (!(init(argc, argv, &idx)))
		return (EXIT_FAILURE);
	if (!(parstostruct(&idx, idx.mv)))
		return (EXIT_FAILURE);
	if (!(bonusinit(&idx)))
		return (0);
	if (argc == 3)
	{
		bmp(&idx);
		return (freexit(&idx, 1));
	}
	if (!(idx.win = mlx_new_window(idx.ptr, idx.w, idx.h, "Cub3D")))
		return (EXIT_FAILURE);
	raycast_loop(&idx, idx.alg, idx.mv);
	mlx_hook(idx.win, 2, 1L << 0, key_input, idx.mv);
	mlx_hook(idx.win, 17, 0, key_exit, &idx);
	mlx_loop(idx.ptr);
	return (0);
}

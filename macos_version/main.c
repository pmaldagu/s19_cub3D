/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:20:43 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 18:40:59 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	visible(t_index *idx)
{
	raycast_loop(idx, idx->alg, idx->mv);
	return (0);
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
	if (argc == 3)
	{
		bmp(&idx);
		return (freexit(&idx, 1));
	}
	if (!(idx.win = mlx_new_window(idx.ptr, idx.w, idx.h, "Cub3D")))
		return (EXIT_FAILURE);
	raycast_loop(&idx, idx.alg, idx.mv);
	mlx_hook(idx.win, 2, 1L << 0, key_input, idx.mv);
	mlx_hook(idx.win, 17, 1L << 17, key_exit, &idx);
	mlx_hook(idx.win, 15, 1L << 16, visible, &idx);
	mlx_loop(idx.ptr);
	return (0);
}

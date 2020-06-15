/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 12:21:29 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 15:07:17 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_addr(t_index *idx, t_text *text, t_sprite *sp)
{
	if (!(sp->img = mlx_xpm_file_to_image(idx->ptr, sp->path, &sp->width, \
					&sp->height)))
	{
		write(1, "Error\nImage failed1\n", 20);
		return (freexit(idx, 1));
	}
	sp->addr = mlx_get_data_addr(sp->img, &sp->bits_per_pixel, \
			&sp->line_length, &text->endian);
	if (!(sp->zbuffer = malloc(sizeof(float) * idx->w)))
	{
		write(1, "Error\nImage failed1\n", 20);
		return (freexit(idx, 1));
	}
	text->addr[0] = mlx_get_data_addr(text->img[0], \
			&text->bits_per_pixel, &text->line_length, &text->endian);
	text->addr[1] = mlx_get_data_addr(text->img[1], \
			&text->bits_per_pixel, &text->line_length, &text->endian);
	text->addr[2] = mlx_get_data_addr(text->img[2], \
			&text->bits_per_pixel, &text->line_length, &text->endian);
	text->addr[3] = mlx_get_data_addr(text->img[3], \
			&text->bits_per_pixel, &text->line_length, &text->endian);
	return (1);
}

int	texture_img(t_index *idx, t_text *text)
{
	if (!(text->img[0] = mlx_xpm_file_to_image(idx->ptr, text->path[0], \
					&text->width, &text->height)))
	{
		write(1, "Error\nImage failed1\n", 20);
		return (freexit(idx, 1));
	}
	if (!(text->img[1] = mlx_xpm_file_to_image(idx->ptr, text->path[1], \
					&text->width, &text->height)))
	{
		write(1, "Error\nImage failed2\n", 20);
		return (freexit(idx, 1));
	}
	if (!(text->img[2] = mlx_xpm_file_to_image(idx->ptr, text->path[2], \
					&text->width, &text->height)))
	{
		write(1, "Error\nImage failed3\n", 20);
		return (freexit(idx, 1));
	}
	if (!(text->img[3] = mlx_xpm_file_to_image(idx->ptr, text->path[3], \
					&text->width, &text->height)))
	{
		write(1, "Error\nImage failed4\n", 20);
		return (freexit(idx, 1));
	}
	return (texture_addr(idx, text, idx->sp));
}

int	cuberror(int fd, t_index *idx, t_img *wall)
{
	idx->mv->idx = idx;
	if (!cub(fd, idx))
	{
		write(1, "Error\nInvalid .cub values\n", 26);
		return (freexit(idx, 1));
	}
	else if (!newmap(idx, idx->mv, fd))
	{
		write(1, "Error\nInvalid map\n", 18);
		return (freexit(idx, 1));
	}
	else if (!(wall->img = mlx_new_image(idx->ptr, idx->w, idx->h)))
	{
		write(1, "Error\nImage failed\n", 19);
		return (freexit(idx, 1));
	}
	wall->addr = mlx_get_data_addr(idx->wall->img, \
			&wall->bits_per_pixel, &wall->line_length, &wall->endian);
	return (texture_img(idx, idx->text));
}

int	s_init(int fd, t_index *idx)
{
	idx->win = NULL;
	idx->h = 0;
	idx->w = 0;
	idx->dir = 0;
	idx->f = 0;
	idx->c = 0;
	idx->mv = NULL;
	idx->alg = NULL;
	idx->wall = NULL;
	idx->text = NULL;
	idx->sp = NULL;
	if (!(idx->alg = malloc(sizeof(t_algo))))
		return (freexit(idx, 0));
	else if (!(idx->wall = malloc(sizeof(t_img))))
		return (freexit(idx, 0));
	else if (!(idx->mv = malloc(sizeof(t_move))))
		return (freexit(idx, 0));
	else if (!(idx->text = malloc(sizeof(t_text))))
		return (freexit(idx, 0));
	else if (!(idx->sp = malloc(sizeof(t_sprite))))
		return (freexit(idx, 0));
	initptr(idx);
	return (cuberror(fd, idx, idx->wall));
}

int	init(int argc, char **argv, t_index *idx)
{
	int fd;

	if (argc == 1 || argc > 3)
	{
		write(1, "Error\nInvalid arguments\n", 24);
		return (0);
	}
	else if (argc >= 2 && ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4))
	{
		write(1, "Error\nInvalid file extension\n", 29);
		return (0);
	}
	else if (argc == 3 && ft_strncmp(argv[2], "--save", ft_strlen(argv[2])))
	{
		write(1, "Error\nInvalid option\n", 21);
		return (0);
	}
	else if ((fd = open(argv[1], O_RDONLY)) <= 0)
	{
		write(1, "Error\nNo such file or directory\n", 32);
		return (0);
	}
	else
		return (s_init(fd, idx));
}

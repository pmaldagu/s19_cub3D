/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 21:11:02 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 16:33:13 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bitshift(char *header, unsigned int value)
{
	header[0] = (unsigned char)(value);
	header[1] = (unsigned char)(value >> 8);
	header[2] = (unsigned char)(value >> 16);
	header[3] = (unsigned char)(value >> 24);
}

void	bmp_header(t_index *idx, t_img *wall, int fd)
{
	char			header[54];
	unsigned int	fsize;

	ft_bzero(header, 54);
	fsize = (idx->h * idx->w) * 4;
	header[0] = 'B';
	header[1] = 'M';
	bitshift(&header[2], fsize + 54);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	bitshift(&header[18], idx->w);
	bitshift(&header[22], -idx->h);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)32;
	raycast_loop(idx, idx->alg, idx->mv);
	write(fd, header, 54);
	write(fd, wall->addr, fsize);
}

int		bmp(t_index *idx)
{
	int fd;

	fd = open("./cub3d.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0)
	{
		write(1, "Error\nBMP failed\n", 17);
		return (0);
	}
	raycast_loop(idx, idx->alg, idx->mv);
	bmp_header(idx, idx->wall, fd);
	return (1);
}

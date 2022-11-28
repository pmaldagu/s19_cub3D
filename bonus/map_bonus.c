/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:27:06 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/04 19:32:52 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		dircheck(char c, t_index *idx, int y, int x)
{
	char	*dir;
	int		i;

	dir = "NSEW";
	i = 0;
	while (dir[i] != '\0')
	{
		if (c == dir[i])
		{
			if (idx->dir != 0)
				return (0);
			else
			{
				idx->dir = c;
				idx->mv->posy = y + 0.5;
				idx->mv->posx = x + 0.5;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int		checkline(char *line, t_index *idx, int l)
{
	int		i;

	i = 0;
	if (line[0] != '1' && line[0] != ' ')
		return (0);
	while (line[i] != '\0')
	{
		if (ft_isalpha(line[i]))
		{
			if (!dircheck(line[i], idx, l, i))
				return (0);
		}
		else if ((line[i] < '0' || line[i] > '2') && line[i] != ' ')
			return (0);
		i++;
	}
	if (line[i - 1] != '1')
		return (0);
	else
		return (1);
}

int		firstline(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		mapcheck(t_index *idx)
{
	int		y;

	y = 0;
	while (idx->mv->map && idx->mv->map[y])
	{
		if (y == 0 && !firstline(idx->mv->map[y]))
			return (0);
		else if (y != 0 && !checkline(idx->mv->map[y], idx, y))
			return (0);
		y++;
	}
	if (!idx->dir)
		return (0);
	if (!idx->mv->map || !*idx->mv->map || !firstline(idx->mv->map[y - 1]))
		return (0);
	return (1);
}

int		storemap(int fd, t_index *idx)
{
	char	*map;
	char	*line;
	char	*tmp;

	line = "";
	while (get_next_line(fd, &line) && line[0] == '\0')
		ft_free(line);
	map = ft_strjoin(line, "\n");
	ft_free(line);
	while (get_next_line(fd, &line))
	{
		tmp = line;
		line = ft_strjoin(line, "\n");
		ft_free(tmp);
		tmp = map;
		map = ft_strjoin(map, line);
		ft_free(tmp);
		ft_free(line);
	}
	ft_free(line);
	idx->mv->map = ft_split(map, '\n');
	ft_free(map);
	return (mapcheck(idx));
}

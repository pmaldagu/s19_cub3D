/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:07:17 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/10 17:23:15 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		colorcheck(char *l, int data, t_index *idx)
{
	int		result;
	int		i;

	i = 1;
	result = (ft_atoi(&l[i]) << 16);
	while ((l[i] == ' ' || ft_isdigit(l[i])) && ft_atoi(&l[i]) < 256)
		i++;
	if (l[i++] != ',')
		return (0);
	result += (ft_atoi(&l[i]) << 8);
	while ((l[i] == ' ' || ft_isdigit(l[i])) && ft_atoi(&l[i]) < 256)
		i++;
	if (l[i++] != ',')
		return (0);
	result += ft_atoi(&l[i]);
	while ((l[i] == ' ' || ft_isdigit(l[i])) && ft_atoi(&l[i]) < 256)
		i++;
	if (data == 7)
		idx->f = result;
	else
		idx->c = result;
	if (l[i] != '\0')
		return (0);
	return (1);
}

int		pathcheck(char *line, int data, t_text *text, t_sprite *sp)
{
	int		i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if (data == 2)
		text->path[0] = ft_strdup(&line[i]);
	else if (data == 3)
		text->path[1] = ft_strdup(&line[i]);
	else if (data == 4)
		text->path[2] = ft_strdup(&line[i]);
	else if (data == 5)
		text->path[3] = ft_strdup(&line[i]);
	else if (data == 6)
		sp->path = ft_strdup(&line[i]);
	while (line[i])
	{
		if (!ft_isprint(line[i]) || line[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

int		rescheck(char *line, t_index *idx)
{
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return (0);
	idx->w = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	if (!ft_isdigit(line[i]))
		return (0);
	idx->h = ft_atoi(&line[i]);
	maxres(idx);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		return (0);
	else
		return (1);
}

int		cubcheck(char *line, t_index *idx)
{
	if (!ft_strncmp(line, "R", 1))
		return (rescheck(line, idx));
	else if (!ft_strncmp(line, "NO", 2))
		return (pathcheck(line, 2, idx->text, idx->sp));
	else if (!ft_strncmp(line, "SO", 2))
		return (pathcheck(line, 3, idx->text, idx->sp));
	else if (!ft_strncmp(line, "WE", 2))
		return (pathcheck(line, 4, idx->text, idx->sp));
	else if (!ft_strncmp(line, "EA", 2))
		return (pathcheck(line, 5, idx->text, idx->sp));
	else if (!ft_strncmp(line, "S", 1))
		return (pathcheck(line, 6, idx->text, idx->sp));
	else if (!ft_strncmp(line, "F", 1))
		return (colorcheck(line, 7, idx));
	else if (!ft_strncmp(line, "C", 1))
		return (colorcheck(line, 8, idx));
	else
		return (0);
}

int		cub(int fd, t_index *idx)
{
	int		i;
	char	*mline;

	i = 1;
	while (i < 9 && get_next_line(fd, &mline))
	{
		if (mline[0] != '\0')
		{
			if (!(cubcheck(mline, idx)))
				return (0);
			else
				i++;
		}
		free(mline);
	}
	return (1);
}

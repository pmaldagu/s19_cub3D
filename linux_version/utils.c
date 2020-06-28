/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:42:13 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/02/18 19:55:46 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	s_free(t_index *idx)
{
	free(idx->alg);
	free(idx->wall);
	free(idx->text);
	free(idx->sp);
	return (0);
}

int	colorpars(char *line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < 3 && line[i + 1])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '0' && ft_isdigit(line[i + 1]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		while (j < 2 && line[i] == ' ')
			i++;
		if (j < 2 && line[i++] != ',')
			return (0);
		j++;
	}
	if (line[i] != '\0')
		return (0);
	return (1);
}

void	ft_swap(t_sprite *sp, int i, int j, char coord)
{
	float	swap;

	if (coord == 'x')
	{
		swap = sp->smapx[i];
		sp->smapx[i] = sp->smapx[j];
		sp->smapx[j] = swap;
	}
	else
	{
		swap = sp->smapy[i];
		sp->smapy[i] = sp->smapy[j];
		sp->smapy[j] = swap;
	}
}

size_t	ft_ostrlen(const char *str, char o)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != o)
			j++;
		i++;
	}
	return (j);
}

char	*ft_ostrjoin(const char *s1, const char *s2, char o)
{
	int	i;
	int	j;
	int	k;
	char	*join;

	i = 0;
	j = 0;
	k = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((join = malloc(sizeof(char) * (ft_ostrlen(s1, o) + \
						ft_strlen(s2) + 1))))
	{
		while (s1[i] != '\0')
		{
			if (s1[i] != o)
				join[k++] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			join[k++] = s2[j++];
		join[k] = '\0';
		return (join);
	}
	return (NULL);
}

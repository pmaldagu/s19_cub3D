/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:27:16 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 16:35:14 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_g(const char *s, int c)
{
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&((char *)s)[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_calloc_g(size_t count, size_t size)
{
	size_t	i;
	char	*calloc;

	i = 0;
	if ((calloc = malloc(size * count)))
	{
		while (i < count * size)
		{
			calloc[i] = '\0';
			i++;
		}
		return (calloc);
	}
	return (NULL);
}

char	*ft_strjoin_g(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if ((join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		while (s1[i] != '\0')
		{
			join[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			join[i++] = s2[j++];
		join[i] = '\0';
		return (join);
	}
	return (NULL);
}

char	*ft_strdup_g(char *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s == NULL)
		return (ft_calloc_g(1, 1));
	if ((str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		while (s[i] != '\0')
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

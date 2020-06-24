/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:27:00 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/22 13:50:49 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nstring(const char *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i])
				i++;
			nb++;
		}
		else if (s[i] == c)
			i++;
	}
	return (nb);
}

static int		ft_sstring(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char		**ft_errfree(char **split, const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_nstring(s, c);
	while (i < j)
	{
		if (split[i] == NULL)
		{
			i = 0;
			while (i < j)
			{
				free(split[i]);
				i++;
			}
			return (NULL);
		}
		i++;
	}
	return (split);
}

static char		*ft_tmpstr(const char *s, char c)
{
	int		i;
	char	*tmp;

	i = 0;
	if ((tmp = malloc(sizeof(char) * (ft_sstring(s, c) + 1))) != 0)
	{
		while (s[i] != c && s[i] != '\0')
		{
			tmp[i] = s[i];
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if ((split = malloc(sizeof(char *) * (ft_nstring(s, c) + 1))) != 0)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
			{
				split[j++] = ft_tmpstr(&s[i], c);
				i = i + ft_sstring(&s[i], c);
			}
			else if (s[i] == c)
				i++;
		}
		split[j] = 0;
		return (ft_errfree(split, s, c));
	}
	return (NULL);
}

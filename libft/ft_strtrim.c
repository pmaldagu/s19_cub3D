/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:06:36 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/22 14:05:42 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ocheck(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int		ft_smalloc(const char *s1, const char *set)
{
	int		i;
	int		nocc;
	int		end;

	i = 0;
	nocc = 0;
	end = ft_strlen(s1);
	while (ft_ocheck(s1[i], set) == 0)
	{
		i++;
		nocc++;
	}
	if ((size_t)nocc == ft_strlen(s1))
		return (0);
	while (ft_ocheck(s1[end - 1], set) == 0)
	{
		end--;
		nocc++;
	}
	return (ft_strlen(s1) - nocc);
}

static char		*ft_emptys(void)
{
	char	*emp;

	if ((emp = malloc(sizeof(char) * 1)) != NULL)
	{
		emp[0] = '\0';
		return (emp);
	}
	return (NULL);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trmd;

	i = 0;
	j = 0;
	if (s1 == NULL || set == NULL)
		return (ft_emptys());
	else if ((trmd = malloc(sizeof(char) * (ft_smalloc(s1, set) + 1))) != 0)
	{
		while (ft_ocheck(s1[j], set) == 0)
			j++;
		while (i < ft_smalloc(s1, set))
			trmd[i++] = s1[j++];
		trmd[i] = '\0';
		return (trmd);
	}
	return (NULL);
}

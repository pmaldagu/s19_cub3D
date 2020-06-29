/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:45:30 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/22 14:03:38 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char			*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*join;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (ft_emptys());
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

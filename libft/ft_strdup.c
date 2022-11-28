/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:50 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/03 11:59:01 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*s2;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0')
		i++;
	if ((s2 = malloc(sizeof(*s2) * (i + 1))) != NULL)
	{
		while (s1[j] != '\0')
		{
			s2[j] = s1[j];
			j++;
		}
		s2[j] = '\0';
		return (s2);
	}
	return (NULL);
}

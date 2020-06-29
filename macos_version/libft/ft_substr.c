/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:32:38 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/24 12:00:41 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*sub;

	i = 0;
	if (s == NULL || start > ft_strlen(s))
	{
		if ((sub = malloc(sizeof(char) * 1)) != 0)
		{
			sub[0] = '\0';
			return (sub);
		}
		return (NULL);
	}
	else if ((sub = malloc(sizeof(char) * (len + 1))) != 0)
	{
		while (i < len && i < ft_strlen(s))
			sub[i++] = s[start++];
		sub[i] = '\0';
		return (sub);
	}
	return (NULL);
}

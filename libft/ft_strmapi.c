/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 14:33:36 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/22 14:04:29 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_emptys(void)
{
	char			*emp;

	if ((emp = malloc(sizeof(char) * 1)) != NULL)
	{
		emp[0] = '\0';
		return (emp);
	}
	return (NULL);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*mapi;

	i = 0;
	j = 0;
	if (s == NULL || f == NULL)
		return (ft_emptys());
	while (s[i] != '\0')
		i++;
	if ((mapi = malloc(sizeof(char) * (i + 1))) != NULL)
	{
		while (j < i)
		{
			mapi[j] = f(j, s[j]);
			j++;
		}
		mapi[i] = '\0';
		return (mapi);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:06:06 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/15 14:08:05 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ilen(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * (-1);
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static char		*ft_scase(int n)
{
	char	*scase;

	if (n == 0)
		scase = ft_strdup("0");
	else
		scase = ft_strdup("-2147483648");
	return (scase);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = ft_ilen(n) - 1;
	if (n == 0 || n == -2147483648)
		return (ft_scase(n));
	if ((num = malloc(sizeof(char) * (ft_ilen(n) + 1))) != 0)
	{
		if (n < 0)
		{
			n = n * (-1);
			num[0] = '-';
		}
		num[len + 1] = '\0';
		while (n != 0)
		{
			num[len--] = (n % 10) + 48;
			n = n / 10;
		}
		return (num);
	}
	return (NULL);
}

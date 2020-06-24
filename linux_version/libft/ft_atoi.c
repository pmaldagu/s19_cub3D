/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:33:25 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/23 16:01:55 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_extreme(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	value;

	i = 0;
	sign = 1;
	value = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = ((value * 10) + (str[i] - 48));
		i++;
	}
	if (value > 2147483648 && value > 9223372036854775807)
		return (ft_extreme(sign));
	return (value * sign);
}

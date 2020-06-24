/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:19:38 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/21 17:01:23 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while(n != 0)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src++;
			return (dst);
		}
		n--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:25:36 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/24 12:01:07 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lst;

	if ((lst = malloc(sizeof(t_list))) != NULL)
	{
		lst->content = content;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}

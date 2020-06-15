/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:51:20 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/23 15:52:47 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (lst != NULL || del != NULL)
	{
		while (*lst)
		{
			del((*lst)->content);
			tmp = *lst;
			(*lst) = (*lst)->next;
			free(tmp);
		}
	}
}

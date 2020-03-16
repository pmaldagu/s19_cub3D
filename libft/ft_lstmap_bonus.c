/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:51:45 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/22 14:26:36 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *nwlst;

	if (lst == 0 || f == 0)
		return (NULL);
	nwlst = ft_lstnew(lst->content);
	if (nwlst == NULL)
		return (NULL);
	nwlst->content = f(lst->content);
	nwlst->next = ft_lstmap(lst->next, f, del);
	return (nwlst);
}

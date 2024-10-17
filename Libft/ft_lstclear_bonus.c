/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:18:49 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/27 14:59:52 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*elem_next;

	elem = *lst;
	while (elem != NULL)
	{
		elem_next = elem->next;
		ft_lstdelone(elem, del);
		elem = elem_next;
	}
	*lst = NULL;
}

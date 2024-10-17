/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:22:19 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/30 18:42:41 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elem;

	if (!lst || !f)
		return (((void *)0));
	elem = 0;
	while (lst)
	{
		new_list = ft_lstnew(f(lst->content));
		if (!new_list)
		{
			ft_lstclear(&elem, del);
			return (((void *)0));
		}
		ft_lstadd_back(&elem, new_list);
		lst = lst->next;
	}
	return (elem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:18:10 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/26 15:23:23 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	counter;
	t_list			*temp;

	counter = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		counter++;
	}
	return (counter);
}

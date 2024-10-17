/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:08:11 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/18 14:34:55 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	char	*dest;

	total = count * size;
	dest = (char *)malloc(total);
	if (dest == ((void *)0))
		return (((void *)0));
	ft_bzero((void *)dest, total);
	return ((void *)dest);
}

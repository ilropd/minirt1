/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:00:44 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/29 20:29:56 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char *)src;
	s2 = (char *)dst;
	if (!src && !dst)
		return (dst);
	if (src >= dst)
		while (len--)
			*s2++ = *s1++;
	else
		while (len--)
			s2[len] = s1[len];
	return (dst);
}

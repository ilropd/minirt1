/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:53:27 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/29 21:07:04 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + j < dstsize - 1 && src[i] != '\0')
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	if (dstsize <= j)
		return (ft_strlen(src) + dstsize);
	return (ft_strlen(src) + j);
}

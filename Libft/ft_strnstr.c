/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:15:00 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/27 15:12:34 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = -1;
	size = ft_strlen(needle);
	if (!size)
		return ((char *)haystack);
	while (haystack[++i] && i < n)
	{
		j = 0;
		while ((needle[j] == haystack[i + j]) && ((i + j) < n))
		{
			if (j == size - 1)
				return ((char *)(haystack + i));
			j++;
		}
	}
	return (((void *)0));
}

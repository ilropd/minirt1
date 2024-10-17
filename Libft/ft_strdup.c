/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 18:42:43 by irozhkov          #+#    #+#             */
/*   Updated: 2023/10/14 19:11:52 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	dest = malloc(sizeof(*src) * (i + 1));
	if (dest == ((void *)0))
		return (((void *)0));
	while (i >= 0)
	{
		dest[i] = src[i];
		i--;
	}
	return (dest);
}

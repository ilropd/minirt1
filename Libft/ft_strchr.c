/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:00:22 by irozhkov          #+#    #+#             */
/*   Updated: 2024/01/02 17:35:42 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s)
	{
		if (*s++ == chr)
			return ((char *)s - 1);
	}
	if (chr == '\0')
		return ((char *)s);
	return (((void *)0));
}

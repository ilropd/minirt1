/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:58:35 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/03 12:33:17 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;
	long	fixit;

	if (n < INT_MIN && n > INT_MAX)
		return (((void *)0));
	fixit = (long)n;
	len = ft_intlen(n);
	s = (char *)malloc(len + 1);
	if (!s)
		return (((void *)0));
	if (fixit < 0)
		fixit = -fixit;
	s[len] = '\0';
	while (len--)
	{
		s[len] = fixit % 10 + '0';
		fixit /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}

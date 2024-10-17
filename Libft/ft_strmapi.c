/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:10:58 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/30 11:55:11 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	i = -1;
	len = ft_strlen(s);
	if (!s || !f)
		return (((void *)0));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (((void *)0));
	while (*(s + ++i))
		*(str + i) = f(i, *(s + i));
	*(str + i) = '\0';
	return (str);
}

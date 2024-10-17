/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:02:16 by irozhkov          #+#    #+#             */
/*   Updated: 2024/01/02 11:50:09 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;
	size_t	s_len;
	size_t	sub_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len < start || len <= 0)
		return ((char *)ft_calloc(1, 1));
	if (len < s_len - (size_t)start)
		sub_len = len;
	else
		sub_len = s_len - start;
	sub = (char *)ft_calloc(sizeof(char), sub_len + 1);
	if (!sub)
		return (((void *)0));
	while (len-- && s[start])
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

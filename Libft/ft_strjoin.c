/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:58:43 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/03 12:34:41 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src && src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	j = -1;
	while (s2 && s2[++j])
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *)malloc(sizeof(*join) * (len + 1));
	if (!join)
		return (((void *)0));
	return (ft_strcat(ft_strcpy(join, s1), s2));
}

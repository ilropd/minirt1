/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:30:49 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/18 12:19:48 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int     ft_isspace(char c);

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int	ft_empty_or_whitespaces(const char *str)
{
	while (*str)
	{
		if (!ft_isspace((char)*str))
			return (0);
		str++;
	}
	return (1);
}

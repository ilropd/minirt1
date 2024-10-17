/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:31:20 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/30 18:55:10 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lettercount(char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != c && str[counter])
		counter++;
	return (counter);
}

static char	*ft_wordstr(char *str, char c)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	len = ft_lettercount(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (((void *)0));
	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

static void	ft_wordarr(char **res, char *str, int c)
{
	size_t	indx;

	indx = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		res[indx] = ft_wordstr(str, c);
		if (!res[indx] && res[0])
		{
			while (indx > 0)
			{
				free(res[indx - 1]);
				indx--;
			}
			free(res);
			return ;
		}
		indx++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
}

static size_t	ft_wordcount(char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		counter++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	counter;

	if (!(s || c))
		return (((void *)0));
	counter = ft_wordcount((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!res)
		return (((void *)0));
	if (s)
	{
		res[counter] = 0;
		ft_wordarr(res, (char *)s, c);
		return (res);
	}
	return (((void *)0));
}

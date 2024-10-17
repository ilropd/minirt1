/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <irozhkov@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:35:26 by irozhkov          #+#    #+#             */
/*   Updated: 2023/09/25 15:07:18 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char			*str;
	unsigned int	i;

	str = (char *)s;
	if (str && f)
	{
		i = 0;
		while (str[i])
		{
			(*f)(i, &str[i]);
			i++;
		}
	}
}

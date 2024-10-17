/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:02:15 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:12:32 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int parse_int(char **str)
{
	char			*start;
	unsigned int	value;

	start = *str;
	value = ft_atoi(start);
	while (**str && ft_isdigit(**str))
		(*str)++;
	return (value);
}

float	parse_float(char **str)
{
	char	*start;
	float	value;

	start = *str;
	value = ft_atof(start);
	while (**str && (ft_isdigit(**str) || **str == '.' || **str == '-'))
		(*str)++;
	return (value);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

char	*skip_whitespace(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:26:51 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:07:57 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	handle_sign(char **str)
{
	int	is_negative;

	is_negative = 0;
	if (**str == '-')
	{
		is_negative = 1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (is_negative);
}

static float	integer_part(char **str)
{
	float	result;

	result = 0.0f;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0f + (**str - '0');
		(*str)++;
	}
	return (result);
}

static float	fractional_part(char **str)
{
	float	fraction;
	float	divisor;

	fraction = 0.0f;
	divisor = 10.0f;
	if (**str == '.')
	{
		(*str)++;
		while (**str >= '0' && **str <= '9')
		{
			fraction += (**str - '0') / divisor;
			divisor *= 10.0f;
			(*str)++;
		}
	}
	return (fraction);
}

float	ft_atof(char *str)
{
	int		is_negative;
	float	result;

	skip_whitespace(str);
	is_negative = handle_sign(&str);
	result = integer_part(&str);
	result += fractional_part(&str);
	if (is_negative == 1)
		return (result *= -1);
	return (result);
}

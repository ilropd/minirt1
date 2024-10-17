/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:54:43 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 16:22:23 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "minirt.h"

int	arg_counter(char **table)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (table[i] && table[i + 1])
		i++;
	if ((ft_strcmp(table[0], "A") == 0 && i != 4)
		|| (ft_strcmp(table[0], "L") == 0 && i != 7)
		|| (ft_strcmp(table[0], "C") == 0 && i != 7)
		|| (ft_strcmp(table[0], "sp") == 0 && i != 7)
		|| (ft_strcmp(table[0], "pl") == 0 && i != 9)
		|| (ft_strcmp(table[0], "cy") == 0 && i != 11))
		flag = 1;
	return (flag);
}

int	check_digit(const char *str, char type)
{
	int	digit;
	int	point;

	digit = 0;
	point = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str))
			digit = 1;
		else if (*str == '.')
		{
			if (type == 'd')
				return (0);
			if (point)
				return (0);
			point = 1;
		}
		else
			return (0);
		str++;
	}
	return (digit);
}

int	check_digit_cycle(char **table, char type, int start, int num_args)
{
	int	end;

	end = start + num_args;
	while (start < end)
	{
		if (check_digit(table[start], type) == 0)
			return (1);
		start++;
	}
	return (0);
}

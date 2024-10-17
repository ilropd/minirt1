/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:51:03 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:26:36 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_ambient(char **table)
{
	int	result;

	result = 0;
	result += arg_counter(table);
	result += check_digit_cycle(table, 'f', 1, 1);
	result += check_digit_cycle(table, 'd', 2, 3);
	result += check_ratio_limit(table, 1, 1);
	result += check_rgb_limit(table, 2, 3);
	return (result);
}

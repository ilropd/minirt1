/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:51:03 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:30:17 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_cylinder(char **table)
{
	int	result;

	result = 0;
	result += arg_counter(table);
	result += check_digit_cycle(table, 'f', 1, 8);
	result += check_digit_cycle(table, 'd', 9, 3);
	result += check_vector_limit(table, 4, 3);
	result += check_zerof_limit(table, 7, 2);
	result += check_rgb_limit(table, 9, 3);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:28:26 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:31:40 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_sphere(char **table)
{
	int	result;

	result = 0;
	result += arg_counter(table);
	result += check_digit_cycle(table, 'f', 1, 4);
	result += check_digit_cycle(table, 'd', 5, 3);
	result += check_zerof_limit(table, 4, 1);
	result += check_rgb_limit(table, 5, 3);
	return (result);
}

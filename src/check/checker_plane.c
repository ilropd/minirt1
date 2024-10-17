/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:51:03 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:30:49 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	check_plane(char **table)
{
	int	result;

	result = 0;
	result += arg_counter(table);
	result += check_digit_cycle(table, 'f', 1, 6);
	result += check_digit_cycle(table, 'd', 7, 3);
	result += check_vector_limit(table, 4, 3);
	result += check_rgb_limit(table, 7, 3);
	return (result);
}

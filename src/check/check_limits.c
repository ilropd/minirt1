/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:23:39 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/27 14:28:57 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "minirt.h"

int	check_rgb_limit(char **table, int start, int num_args)
{
	int	end;
	int	to_check;

	end = start + num_args;
	while (start < end)
	{
		if (ft_strlen(table[start]) > 3)
			return (1);
		to_check = ft_atoi(table[start]);
		if (to_check < 0 || to_check > 255)
			return (1);
		start++;
	}
	return (0);
}

int	check_degree_limit(char **table, int start, int num_args)
{
	int end;
	int	to_check;

	end = start + num_args;
	while (start < end)
	{
		if (ft_strlen(table[start]) > 3)
			return (1);
		to_check = ft_atoi(table[start]);
		if (to_check < 0 || to_check > 180)
			return (1);
		start++;
	}
	return (0);
}

int	check_ratio_limit(char **table, int start, int num_args)
{
	int		end;
	float	to_check;

	end = start + num_args;
	while (start < end)
	{
		to_check = ft_atof(table[start]);
		if (to_check < 0.0 || to_check > 1.0)
			return (1);
		start++;
	}
	return (0);
}

int	check_vector_limit(char **table, int start, int num_args)
{
	int		end;
	float	to_check;

	end = start + num_args;
	while (start < end)
	{
		to_check = ft_atof(table[start]);
		if (to_check < -1.0 || to_check > 1.0)
			return (1);
		start++;
	}
	return (0);
}

int	check_zerof_limit(char **table, int start, int num_args)
{
	int		end;
	float	to_check;

	end = start + num_args;
	while (start < end)
	{
		to_check = ft_atof(table[start]);
		if (to_check <= 0.0)
			return (1);
		start++;
	}
	return (0);
}

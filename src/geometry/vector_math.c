/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:45:52 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/05 18:08:55 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_sub(t_vector *vec1, t_vector *vec2)
{
	t_vector	*res;

	res = new_vector(vec2->x - vec1->x, vec2->y - vec1->y, vec2->z - vec1->z);
	return (res);
}

t_vector    *vector_add(t_vector *vec1, t_vector *vec2)
{
	t_vector	*res;

	res = new_vector(vec2->x + vec1->x, vec2->y + vec1->y, vec2->z + vec1->z);
	return (res);
}

t_vector	*vector_mult(t_vector *vec, float num)
{
	t_vector	*res;

	res = new_vector(vec->x * num, vec->y * num, vec->z * num);
	return (res);
}

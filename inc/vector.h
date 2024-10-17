/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:38:50 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/05 18:10:54 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* vector.c */
t_vector	*new_vector(float x, float y, float z);
float		vector_len(t_vector *vec);
void		vector_normalize(t_vector *vec);

/* vector_prod.c */
float		vector_dot_prod(t_vector *vec1, t_vector *vec2);
t_vector	*vector_cross_prod(t_vector *vec1, t_vector *vec2);

/* vector_math.c*/
t_vector	*vector_sub(t_vector *vec1, t_vector *vec2);
t_vector	*vector_add(t_vector *vec1, t_vector *vec2);
t_vector	*vector_mult(t_vector *vec, float num);

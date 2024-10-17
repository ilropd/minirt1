/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:56:14 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/12 17:16:22 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_INTERSECTION_H
# define CYLINDER_INTERSECTION_H

# include "minirt.h"

void	quadratic(t_mrt *mrt, t_vector *ray, t_vector *cam_cyl, float *q);
int		cylinder_intersection(t_mrt *mrt, t_vector *ray);

#endif

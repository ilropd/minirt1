/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:37:37 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/12 14:36:59 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane_intersection.h"

int	plane_intersection(t_mrt *mrt, t_vector *ray)
{
	t_vector	*cam_plane;
	float		denom;
	float		dist;
	float		on_plane;

	denom = vector_dot_prod(ray, mrt->scene->pls[0].plane->orient);
	cam_plane = vector_sub(mrt->scene->camera->center,
			mrt->scene->pls[0].plane->center);
	if (fabs(denom) < 1e-6)
	{
		on_plane = vector_dot_prod(cam_plane, mrt->scene->pls[0].plane->orient);
		free(cam_plane);
		if (fabs(denom) < 1e-6)
			return ((mrt->scene->pls[0].plane->r << 16)
				| (mrt->scene->pls[0].plane->g << 8)
				| (mrt->scene->pls[0].plane->b));
		else
			return (0);
	}
	dist = vector_dot_prod(cam_plane, mrt->scene->pls[0].plane->orient) / denom;
	free(cam_plane);
	if (dist != 0)
		return ((mrt->scene->pls[0].plane->r << 16)
			| (mrt->scene->pls[0].plane->g << 8)
			| (mrt->scene->pls[0].plane->b));
	return (0);
}

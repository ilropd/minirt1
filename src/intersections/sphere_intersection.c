/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:51:29 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/05 18:59:52 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere_intersection.h"

int	sphere_intersection(t_mrt *mrt, t_vector *ray)
{
	float		a;
	float		b;
	float		c;
	float		discr;
	float		dist1;
	float		dist2;
//	float		dist[2];
	t_vector	*cam_sphere;

//	dist = 0;
//	printf("-!-!-!-!-----> %f\n", mrt->scene->sps[0].sphere->center->z);
	cam_sphere = vector_sub(mrt->scene->camera->center, mrt->scene->sps[0].sphere->center);
	a = vector_dot_prod(ray, ray);
	b = 2 * vector_dot_prod(cam_sphere, ray);
	c = vector_dot_prod(cam_sphere, cam_sphere) - (mrt->scene->sps[0].sphere->radius * mrt->scene->sps[0].sphere->radius);
	discr = (b * b) - (4 * a * c);
	free(cam_sphere);
//	printf("---> discr: %f\n", discr);
	if (discr < 0)
		return (0);
	dist1 = (b + sqrt(discr)) / (2 * a);
	dist2 = (b - sqrt(discr)) / (2 * a);
//	printf("----->dist: %f\n", dist);
	if (dist1 > 0)
		return ((mrt->scene->sps[0].sphere->r << 16) | (mrt->scene->sps[0].sphere->g << 8) | mrt->scene->sps[0].sphere->b);
	return (0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 14:55:23 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/13 18:24:11 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "cylinder_intersection.h"

void	quadratic(t_mrt *mrt, t_vector *ray, t_vector *cam_cyl, float *q)
{
	q[0] = vector_dot_prod(ray, ray) - (vector_dot_prod(ray, mrt->scene->cys[0].cylinder->orient) * vector_dot_prod(ray, mrt->scene->cys[0].cylinder->orient));
	q[1] = 2.0 * (vector_dot_prod(cam_cyl, ray) - (vector_dot_prod(cam_cyl, mrt->scene->cys[0].cylinder->orient) * vector_dot_prod(ray, mrt->scene->cys[0].cylinder->orient)));
	q[2] = vector_dot_prod(cam_cyl, cam_cyl) - (vector_dot_prod(cam_cyl, mrt->scene->cys[0].cylinder->orient) * vector_dot_prod(cam_cyl, mrt->scene->cys[0].cylinder->orient)) - ((mrt->scene->cys[0].cylinder->diameter / 2) * (mrt->scene->cys[0].cylinder->diameter / 2));
}
/*
static int circle_intersection(t_mrt *mrt, t_vector *ray, t_plane *cap)
{
    t_vector    *cam_cap;
    float       denom;
    float       dist;
    float       on_plane;

    denom = vector_dot_prod(ray, cap->orient);
    cam_cap = vector_sub(mrt->scene->camera->center, cap->center);
    if (fabs(denom) < 1e-6)
    {
        on_plane = vector_dot_prod(cam_cap, cap->orient);
        free(cam_cap);
        if (fabs(denom) < 1e-6)
            return ((cap->r << 16)
                | (cap->g << 8)
                | (cap->b));
        else
            return (0);
    }
    dist = vector_dot_prod(cam_cap, cap->orient) / denom;
    free(cam_cap);
    if (dist != 0)
        return ((cap->r << 16)
            | (cap->g << 8)
            | (cap->b));
    return (0);
}*/

static int circle_intersection(t_mrt *mrt, t_vector *ray, t_plane *cap)
{
    t_vector    *cam_cap;   // Vector from camera to cap center
    t_vector    *intersection_point;  // The intersection point between ray and plane
    t_vector    *to_center;  // Vector from intersection point to circle center
    float       denom;      // Dot product between ray and plane normal (cap->orient)
    float       dist;       // Distance to intersection point along the ray
    float       radius_sq;  // Square of the circle's radius
    float       distance_sq; // Square of the distance from the intersection point to the circle center

    denom = vector_dot_prod(ray, cap->orient);
    cam_cap = vector_sub(mrt->scene->camera->center, cap->center);

    if (fabs(denom) < 1e-6)
    {
        free(cam_cap);
        return (0);
    }

    dist = vector_dot_prod(cam_cap, cap->orient) / denom;
    free(cam_cap);

    if (dist < 0)
        return (0);

    // Calculate the intersection point: P = camera_position + ray_direction * dist
    intersection_point = new_vector(
        mrt->scene->camera->center->x + ray->x * dist,
        mrt->scene->camera->center->y + ray->y * dist,
        mrt->scene->camera->center->z + ray->z * dist
    );

    // Calculate the vector from the intersection point to the center of the circle
    to_center = vector_sub(intersection_point, cap->center);

    // Compute squared distance from the intersection point to the center of the circle
    distance_sq = vector_dot_prod(to_center, to_center);
    radius_sq = ((mrt->scene->cys[0].cylinder->diameter / 2) * (mrt->scene->cys[0].cylinder->diameter / 2));

    free(intersection_point);
    free(to_center);

    // If the distance from the center to the intersection point is less than the radius, it's inside the circle
    if (distance_sq <= radius_sq)
    {
        // Return the color of the cap (in RGB)
        return ((cap->r << 16) | (cap->g << 8) | (cap->b));
    }

    // If outside the circle's radius, no intersection
    return (0);
}


static int	cap_intersection(t_mrt *mrt, t_vector *ray)
{
	t_plane		*top_cap;
	t_plane		*bottom_cap;
	t_vector	*center_cap;
	t_vector	*temp;
	int			color;

	center_cap = vector_mult(mrt->scene->cys[0].cylinder->orient, mrt->scene->cys[0].cylinder->height / 2);
	temp = vector_add(mrt->scene->cys[0].cylinder->center, center_cap);
	top_cap = new_plane_mrt(temp, mrt->scene->cys[0].cylinder->orient, mrt, 0);
	free(temp);
	temp = vector_sub(mrt->scene->cys[0].cylinder->center, center_cap);
	bottom_cap = new_plane_mrt(temp, mrt->scene->cys[0].cylinder->orient, mrt, 0);
	free(temp);
	color = circle_intersection(mrt, ray, top_cap);
	if (color == 0)
		color = circle_intersection(mrt, ray, bottom_cap);
	free(center_cap);
	free(top_cap);
	free(bottom_cap);
	return (color);
	
}

int	cylinder_intersection(t_mrt *mrt, t_vector *ray)
{
	t_vector	*cam_cyl;
	t_vector	*intersection_1;
	t_vector	*intersection_2;
	t_vector	*int1_cyl;
	t_vector	*int2_cyl;
	float		*q;
	float		discr;
	float		dist_1;
	float		dist_2;
	float		height_1;
	float		height_2;

	q = malloc(3 * sizeof(float));
    if (!q)
		return (0);
	cam_cyl = vector_sub(mrt->scene->camera->center, mrt->scene->cys[0].cylinder->center);
	quadratic(mrt, ray, cam_cyl, q);
	discr = (q[1] * q[1]) - (4.0 * q[0] * q[2]);
//	printf("discr: %f\n", discr);
//	printf("q0: %f, q1: %f, q2: %f\n", q[0], q[1], q[2]);
/*	if (discr < 0 || q[0] == 0)
	{
		free(q);
		free(cam_cyl);
		return (0);
    }*/
	dist_1 = (q[1] - sqrt(discr)) / (2.0 * q[0]);
    dist_2 = (q[1] + sqrt(discr)) / (2.0 * q[0]);
	intersection_1 = new_vector(mrt->scene->camera->center->x + ray->x * dist_1,mrt->scene->camera->center->y + ray->y * dist_1, mrt->scene->camera->center->z + ray->z * dist_1);
	intersection_2 = new_vector(mrt->scene->camera->center->x + ray->x * dist_2, mrt->scene->camera->center->y + ray->y * dist_2, mrt->scene->camera->center->z + ray->z * dist_2);
	int1_cyl = vector_sub(intersection_1, mrt->scene->cys[0].cylinder->center);
	int2_cyl = vector_sub(intersection_2, mrt->scene->cys[0].cylinder->center);
	height_1 = fabs(vector_dot_prod(int1_cyl, mrt->scene->cys[0].cylinder->orient));
	height_2 = fabs(vector_dot_prod(int2_cyl, mrt->scene->cys[0].cylinder->orient));
//	FILE *file = fopen("heights.txt", "a");
//	fprintf(file, "h_1: %f, h_2: %f\n", height_1, height_2);
//	fclose(file);
// Check for intersection with the cylinder caps
	free(q);
	free(cam_cyl);
	free(intersection_1);
	free(intersection_2);
	free(int1_cyl);
	free(int2_cyl);
	if (height_1 >= 0 && height_1 <= mrt->scene->cys[0].cylinder->height)
		return ((mrt->scene->cys[0].cylinder->r << 16) | (mrt->scene->cys[0].cylinder->g << 8) | mrt->scene->cys[0].cylinder->b);
	else if (height_2 >= 0 && height_2 <= mrt->scene->cys[0].cylinder->height)
		return ((mrt->scene->cys[0].cylinder->r << 16) | (mrt->scene->cys[0].cylinder->g << 8) | mrt->scene->cys[0].cylinder->b);
	return (cap_intersection(mrt, ray));
//	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:05:12 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/12 16:40:38 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	*right_comp_calc(t_vector *up, t_mrt *mrt, float ray_x)
{
	t_vector	*res;
	t_vector	*right;

	right = vector_cross_prod(up, mrt->scene->camera->orient);
	res = vector_mult(right, ray_x);
	free(right);
	return (res);
}


static t_vector	*camray(t_mrt *mrt, float ray_x, float ray_y)
{
	t_vector    *up;
	t_vector	*right_comp;
	t_vector	*up_comp;
	t_vector	*hor_vert;
	t_vector	*res;

	up = new_vector(0, 1, 0);
	right_comp = right_comp_calc(up, mrt, ray_x);
	up_comp = vector_mult(up, ray_y);
	hor_vert = vector_add(right_comp, up_comp);
	res = vector_add(hor_vert, mrt->scene->camera->orient);
	free(up);
	free(right_comp);
	free(up_comp);
	free(hor_vert);
	return (res);
}

void	ray_tracing(t_mrt *mrt)
{
	int		mlx_x;
	int		mlx_y;
	float	angle_x;
	float	angle_y;
	int		color;
	float	ray_x;
	float	ray_y;
	t_vector	*ray;
	t_vplane	*vplane;
	
	vplane = get_vplane(WIDTH, HEIGHT, mrt->scene->camera->fov);
	angle_y = HEIGHT / 2;
	mlx_y = 0;
	while (angle_y >= (HEIGHT / 2) * (-1))
	{
		ray_y = angle_y * vplane->y_pixel;
		angle_x = (WIDTH / 2) * (-1);
		mlx_x = 0;
		while (angle_x <= (WIDTH / 2))
		{
			ray_x = angle_x *vplane->x_pixel;
			ray = camray(mrt, ray_x, ray_y);
			vector_normalize(ray);
/*			if (sphere_intersection(mrt, ray))
				color = 16777215;
			else
				color = 0;*/
//			color = sphere_intersection(mrt, ray);
//			color = plane_intersection(mrt, ray);
			color = cylinder_intersection(mrt, ray);
			mlx_pixel_put(mrt->connection, mrt->window, mlx_x, mlx_y, color);
			free(ray);
//			printf("mlx_x: %d, mlx_y: %d\n", mlx_x, mlx_y);
			angle_x++;
			mlx_x++;
		}
		angle_y--;
		mlx_y++;
	}
	free(vplane);
}

t_vplane	*get_vplane(int width, int height, unsigned int fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		exit(1); // to change
	aspect_ratio = width / height;
	vplane->width = (tan((float)fov / 2 * (M_PI / 180))) * 2;
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}

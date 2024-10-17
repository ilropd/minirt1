/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:10:33 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/05 12:29:05 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_cylinder(char **table, t_scene *scene)
{    
	t_cylinder	*cylinder;
	t_vector	*center;
	t_vector	*orient;

	if (check_cylinder(table))
		return (printf("Error\nWrong arguments for cylinder\n"), 1);
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)    
		return (printf("Error\nCylinder memory allocation failed\n"), 1);
	cylinder->type = table[0];
	center = new_vector(ft_atof(table[1]), ft_atof(table[2]), ft_atof(table[3]));
	orient = new_vector(ft_atof(table[4]), ft_atof(table[5]), ft_atof(table[6]));
	cylinder->center = center;
	cylinder->orient = orient;
	cylinder->diameter = ft_atof(table[7]);
	cylinder->height = ft_atof(table[8]);
	cylinder->r = ft_atoi(table[9]);
	cylinder->g = ft_atoi(table[10]);
	cylinder->b = ft_atoi(table[11]);
	printf("Cylinder settings:\n\ttype: %s\n\tcenter: %f | %f | %f\n\torientation: %f | %f | %f\n\tdiameter: %f\n\theight: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", cylinder->type, cylinder->center->x, cylinder->center->y, cylinder->center->z, cylinder->orient->x, cylinder->orient->y, cylinder->orient->z, cylinder->diameter, cylinder->height, cylinder->r, cylinder->g, cylinder->b);
	scene->cys_count++;
	return (add_cylinder(scene, cylinder));
}

int	init_plane(char **table, t_scene *scene)
{
	t_plane		*plane;
	t_vector	*center;
	t_vector	*orient;

	if (check_plane(table))
		return (printf("Error\nWrong arguments for plane\n"), 1);
	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (printf("Error\nPlain memory allocation failed\n"), 1);
	plane->type = table[0];
	center = new_vector(ft_atof(table[1]), ft_atof(table[2]), ft_atof(table[3]));
	orient = new_vector(ft_atof(table[4]), ft_atof(table[5]), ft_atof(table[6]));
	plane->center = center;
	plane->orient = orient;
	plane->r = ft_atoi(table[7]);
	plane->g = ft_atoi(table[8]);
	plane->b = ft_atoi(table[9]);
	printf("Plane settings:\n\ttype: %s\n\tcenter: %f | %f | %f\n\torientation: %f | %f | %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", plane->type, plane->center->x, plane->center->y, plane->center->z, plane->orient->x, plane->orient->y, plane->orient->z, plane->r, plane->g, plane->b);
    scene->pls_count++;
	return (add_plane(scene, plane));
}

int	init_sphere(char **table, t_scene *scene)
{
	t_sphere	*sphere;
	t_vector	*center;	

	if (check_sphere(table))
		return (printf("Error\nWrong arguments for sphere\n"), 1);
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (printf("Error\nSphere memory allocation failed\n"), 1);
	sphere->type = table[0];
	center = new_vector(ft_atof(table[1]), ft_atof(table[2]), ft_atof(table[3]));
	sphere->center = center;
	sphere->diameter = ft_atof(table[4]);
	sphere->radius = sphere->diameter / 2;
	sphere->r = ft_atoi(table[5]);
	sphere->g = ft_atoi(table[6]);
	sphere->b = ft_atoi(table[7]);
	printf("Sphere settings:\n\ttype: %s\n\tcenter: %f | %f | %f\n\tdiameter: %f\n\tradius: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", sphere->type, sphere->center->x, sphere->center->y, sphere->center->z, sphere->diameter, sphere->radius, sphere->r, sphere->g, sphere->b);
    scene->sps_count++;
	return (add_sphere(scene, sphere));
}

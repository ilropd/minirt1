/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_unique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:06:45 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/17 14:04:10 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int    init_camera(char **table, t_scene *scene)
{
	t_vector	*center;
	t_vector	*orient;

	if (scene->camera)
		return (printf("Error\nCamera is not unique\n"), 1);
	if (check_camera(table))
		return (printf("Error\nWrong arguments for spot light\n"), 1);
	scene->camera = (t_camera *)malloc(sizeof(t_camera));
	if (!scene->camera)
		return(printf("Error\nMemory allocation failed for camera\n"), 1);
	scene->camera->type = table[0];
	center = new_vector(ft_atof(table[1]), ft_atof(table[2]), ft_atof(table[3]));
	orient = new_vector(ft_atof(table[4]), ft_atof(table[5]), ft_atof(table[6]));
	scene->camera->center = center;
	scene->camera->orient = orient;
	scene->camera->fov = ft_atoi(table[7]);
	printf("Camera settings:\n\ttype: %s\n\tcenter: %f | %f | %f\n\torientation: %f | %f | %f\n\tfov: %d\n", scene->camera->type, scene->camera->center->x, scene->camera->center->y, scene->camera->center->z, scene->camera->orient->x, scene->camera->orient->y, scene->camera->orient->z, scene->camera->fov);
	return (0);
}

int	init_spot(char **table, t_scene *scene)
{
//	t_light	*light;

/*	if (scene->light != NULL)
		return (printf("Error\nLight is not unique\n"), 1);*/
	if (check_spot(table))
		return (printf("Error\nWrong arguments for spot light\n"), 1);
/*	scene->light = (t_light *)malloc(sizeof(t_light));
	if (!scene->light)
		return (printf("Error\nMemory allocation failed for light\n"), 1);*/
	scene->light.type = table[0];
	scene->light.center = *new_vector(ft_atof(table[1]), ft_atof(table[2]), ft_atof(table[3]));
//	scene->light->center = center;
	scene->light.brightness = ft_atof(table[4]);
	scene->light.color[0] = ft_atoi(table[5]);
	scene->light.color[1] = ft_atoi(table[6]);
	scene->light.color[2] = ft_atoi(table[7]);
	printf("Spot light settings:\n\ttype: %s\n\tcenter: %f | %f | %f\n\tbrightness: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", scene->light.type, scene->light.center.x, scene->light.center.y, scene->light.center.z, scene->light.brightness ,scene->light.color[0], scene->light.color[1], scene->light.color[2]);
	return (0);
}

int	init_ambient(char **table, t_scene *scene)
{
	if (scene->ambient)
		return (printf("Error\nAmbient light is not unique\n"), 1);
	if (check_ambient(table))
		return (printf("Error\nWrong arguments for ambient light\n"), 1);
	scene->ambient = (t_amb_light *)malloc(sizeof(t_amb_light));
	if (!scene->ambient)
		return (printf("Error\nMemory allocation for ambient light failed\n"), 1);
	scene->ambient->type = table[0];
    scene->ambient->ratio = ft_atof(table[1]);
    scene->ambient->r = ft_atoi(table[2]);
    scene->ambient->g = ft_atoi(table[3]);
    scene->ambient->b = ft_atoi(table[4]);
	printf("Ambient light settings:\n\ttype: %s\n\tratio: %f\n\tred: %d\n\tgreen: %d\n\tblue: %d\n", scene->ambient->type, scene->ambient->ratio, scene->ambient->r, scene->ambient->g, scene->ambient->b);
	return (0);
}

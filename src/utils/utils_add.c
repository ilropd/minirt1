/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:51:47 by irozhkov          #+#    #+#             */
/*   Updated: 2024/09/22 15:09:31 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	add_sphere(t_scene *scene, t_sphere *new_sphere)
{
	t_sps_node *new_node;

	new_node = (t_sps_node *)malloc(sizeof(t_sps_node));
	if (!new_node)
		return (printf("Error\nMemory allocation failed for sphere node\n"), 1);
	new_node->sphere = new_sphere;
	new_node->next = scene->sps;
	scene->sps = new_node;
	return (0);
}

int	add_plane(t_scene *scene, t_plane *new_plane)
{
	t_pls_node *new_node;

	new_node = (t_pls_node *)malloc(sizeof(t_pls_node));
	if (!new_node)
		return (printf("Error\nMemory allocation failed for plane node\n"), 1);
	new_node->plane = new_plane;
	new_node->next = scene->pls;
	scene->pls = new_node;
	return (0);
}

int	add_cylinder(t_scene *scene, t_cylinder *new_cylinder)
{
	t_cys_node *new_node;

	new_node = (t_cys_node *)malloc(sizeof(t_cys_node));
	if (!new_node)
		return (printf("Error\nMemory allocation failed for cylinder node\n"), 1);
	new_node->cylinder = new_cylinder;
	new_node->next = scene->cys;
	scene->cys = new_node;
	return (0);
}

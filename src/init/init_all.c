/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:27:04 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/17 13:10:05 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	init_scene(t_scene *scene)
{
	int	sps_count;
	int	pls_count;
	int cys_count;

	scene->ambient = NULL;
//	scene->light = NULL;
	scene->camera = NULL;
	scene->sps = NULL;
	scene->pls = NULL;
	scene->cys = NULL;
	sps_count = 0;
	pls_count = 0;
	cys_count = 0;
}

int	init_all(char **table, t_scene *scene)
{
	int	i;

	i = 0;
	if (!table)
		return (printf("Error\nEmpty table of scene arguments\n"), 1);
	if (ft_strcmp(table[0], "A") == 0 && ft_strlen(table[0]) == 1)
		i = init_ambient(table, scene);
	else if (ft_strcmp(table[0], "L") == 0 && ft_strlen(table[0]) == 1)
        i = init_spot(table, scene);
	else if (ft_strcmp(table[0], "C") == 0 && ft_strlen(table[0]) == 1)
        i = init_camera(table, scene);
	else if (ft_strcmp(table[0], "sp") == 0 && ft_strlen(table[0]) == 2)
		i = init_sphere(table, scene);
	else if (ft_strcmp(table[0], "pl") == 0 && ft_strlen(table[0]) == 2)
		i = init_plane(table, scene);
	else if (ft_strcmp(table[0], "cy") == 0 && ft_strlen(table[0]) == 2)
        i = init_cylinder(table, scene);
	else
		return (printf("Error\nWrong scene arguments\n"), 1);
	return (i);
}

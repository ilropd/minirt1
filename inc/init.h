/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:19:36 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/03 13:54:29 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "minirt.h"
# include "structures.h"

/* init_all.c */
void	init_scene(t_scene *scene);
int		init_all(char **table, t_scene *scene);

/* init_figures.c */
int		init_cylinder(char **table, t_scene *scene);
int		init_plane(char **table, t_scene *scene);
int		init_sphere(char **table, t_scene *scene);

/* init_unique.c */
int		init_camera(char **table, t_scene *scene);
int		init_spot(char **table, t_scene *scene);
int		init_ambient(char **table, t_scene *scene);

#endif

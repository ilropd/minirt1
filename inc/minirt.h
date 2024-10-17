/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:34:32 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/15 15:25:26 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <ctype.h>
# include <fcntl.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h> 
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# include "libft.h"
# include "mlx.h"

# include "check.h"
# include "err.h"
# include "init.h"
# include "parsing.h"
# include "plane.h"
# include "structures.h"
# include "utils.h"
# include "vector.h"

# include "sphere_intersection.h"
# include "plane_intersection.h"
# include "cylinder_intersection.h"

/* render_init */
int	render_init(t_mrt *mrt, t_scene *scene);

/* render.c */
void		ray_tracing(t_mrt *mrt);
t_vplane	*get_vplane(int width, int height, unsigned int fov);

/* key_handler */
int	destroy_handler(t_mrt *mrt);
int	key_handler(int key, t_mrt *mrt);
int	mouse_handler(int button, int x, int y,  t_mrt *mrt);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:50:19 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/13 17:37:19 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "structures.h"

t_plane	*new_plane_mrt(t_vector *center, t_vector *orient, t_mrt *mrt, int n)
{
	t_plane	*res;

	res = (t_plane *)malloc(sizeof(t_plane));
	if (!res)
		return (printf("Error\nPlain memory allocation failed\n"), NULL);
	res->center = center;
	res->orient = orient;
	res->r = mrt->scene->cys[n].cylinder->r;
	res->g = mrt->scene->cys[n].cylinder->g;
	res->b = mrt->scene->cys[n].cylinder->b;
	return (res);
}

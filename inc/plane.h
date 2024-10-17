/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:58:53 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/13 17:00:02 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "minirt.h"

t_plane	*new_plane_mrt(t_vector *center, t_vector *orient, t_mrt *mrt, int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:22:17 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/10 15:53:53 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*static void	mrt_init(t_mrt *mrt)
{
}
*/

static void	events_init(t_mrt *mrt)
{
	if (!mrt->window)
    {
        printf("Error: mrt->window is NULL\n");
        return	;
    }
	mlx_hook(mrt->window, 2, 1L << 0, key_handler, mrt);
	mlx_hook(mrt->window, 17, 0L, destroy_handler, mrt);
//	mlx_hook(mrt->window, 4, 1L << 2, mouse_handler, mrt);
}

int	render_init(t_mrt *mrt, t_scene *scene)
{
	mrt->name = "mandatory";
	mrt->scene = scene;
	if ((mrt->connection = mlx_init()) == NULL)
		return (printf("Error\nMemory allocation for mlx connection failed\n"), 1);
	if ((mrt->window = mlx_new_window(mrt->connection, WIDTH, HEIGHT, mrt->name)) == NULL)
		return (printf("Error\nMemory allocation for mlx window failed\n"), mlx_destroy_window(mrt->connection, mrt->window), free(mrt->connection), 1);
	if ((mrt->img.img_ptr = mlx_new_image(mrt->connection, WIDTH, HEIGHT)) == NULL)
		return (printf("Error\nMemory allocation for mlx image failed\n"), mlx_destroy_window(mrt->connection, mrt->window), free(mrt->connection), 1);
	mrt->img.pxl_ptr = mlx_get_data_addr(mrt->connection, &mrt->img.bpp, &mrt->img.line_len, &mrt->img.endian);
	events_init(mrt);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:42:25 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/10 16:07:23 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	destroy_handler(t_mrt *mrt)
{
	printf ("X button pressed\n");
	if (mrt->scene != NULL)
    {
        clear_scene(mrt->scene);
        free(mrt->scene);
    }
	if (mrt->img.img_ptr)
		mlx_destroy_image(mrt->connection, mrt->img.img_ptr);
	if (mrt->window)
		mlx_destroy_window(mrt->connection, mrt->window);
	if (mrt->connection)
	{
		mlx_destroy_display(mrt->connection);
		free(mrt->connection);
	}
	exit(0);
}

int	key_handler(int key, t_mrt *mrt)
{
	printf("----> key: %d\n", key);
	if (key == 65307)
	{
		printf("----> ESC button pressed\n");
		if (mrt->img.img_ptr)
			mlx_destroy_image(mrt->connection, mrt->img.img_ptr);
		if (mrt->window)
			mlx_destroy_window(mrt->connection, mrt->window);
		if (mrt->connection)
		{
			mlx_destroy_display(mrt->connection);
			free(mrt->connection);
		}
		clear_scene(mrt->scene);
		free(mrt->scene);
		exit(1);
	}
	return (0);
}

int	mouse_handler(int button, int x, int y,  t_mrt *mrt)
{
	(void)x;
	(void)y;
	(void)mrt;
	printf("---> button: %d\n", button);
	return (0);
}

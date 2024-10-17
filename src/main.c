/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:34:41 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/15 15:35:34 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	file_checker(char **argv)
{
	struct stat	st;
	int			fd;

	if (access(argv[1], F_OK) != 0)
	{
		printf("%s%s", ERROR, NE_FILE);
		exit(1);
	}
	if (stat(argv[1], &st) != 0)
	{
		printf("%s%s", ERROR, RET_FILE);
		exit(1);
	}
	if (st.st_size == 0)
	{
		printf("%s%s", ERROR, E_FILE);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("%s%s", ERROR, RO_FILE);
		exit(1);
	}
	close(fd);
}

static void	arg_checker(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		printf("%s%s", ERROR, ARGS);
		exit(1);
	}
	len = ft_strlen(argv[1]);
	if (len <= 3 || ft_strcmp(argv[1] + len - 3, ".rt"))
	{
		printf("%s%s", ERROR, WF_FILE);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_scene	*scene;
	t_mrt	mrt;

	arg_checker(argc, argv);
	file_checker(argv);
	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (printf("Error\nScene memory allocation failed\n"), 1);
	init_scene(scene);
	if (parsing_scene(argv, scene))
		error_exit(scene);
	render_init(&mrt, scene);
	ray_tracing(&mrt);
	mlx_loop(mrt.connection);
	clear_scene(scene);
	free(scene);
	return (0);
}

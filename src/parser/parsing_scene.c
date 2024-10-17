/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:02:38 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/08 12:38:27 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

int	open_file(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nProblem with fd\n");
		return (-1);
	}
	return (fd);
}

int	process_line(char *str, t_scene *scene)
{
	char	**table;

	if (ft_empty_or_whitespaces(str))
		return (0);
	table = parsing_table();
	if (!table)
	{
		printf("Error\nParsing failed\n");
		return (1);
	}
	if (parse_string(table, str))
	{
		printf("Error\nParsing failed\n");
		free_parsing_table(table);
		return (1);
	}
	if (init_all(table, scene))
	{
		printf("Error\nObject initialization failed\n");
		free_parsing_table(table);
		return (1);
	}
	free_parsing_table(table);
	return (0);
}

int	handle_error_cleanup(char *str, int fd, int line)
{
	if (str)
		free(str);
	close(fd);
	return (printf("Error\nLine %d failed\n", line), 1);
}

int	parsing_scene(char **argv, t_scene *scene)
{
	int		fd;
	int		line;
	char	*str;

	line = 1;
	str = NULL;
	fd = open_file(argv);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (process_line(str, scene))
			return (handle_error_cleanup(str, fd, line));
		free(str);
		str = get_next_line(fd);
		line++;
	}
	close(fd);
	return (0);
}

/*
int	parsing_scene(char **argv, t_scene *scene)
{
	int		fd;
	int		line;
	char	*str;
	char	**table;
	int		i;

	line = 1;
	str = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf("Error\nProblem with fd\n"), 1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		if (ft_empty_or_whitespaces(str))
		{
			free(str);
			str = get_next_line(fd);
			line++;
			continue ;
		}
		printf("Line %d - %s", line, str);
		table = parsing_table();
		if (!table)
			return (printf("Error\nParsing failed\n"), free(str), close(fd), 1);
		if (parse_string(table, str))
			return (printf("Error\nParsing failed\n"), free(str), free_parsing_table(table), close(fd), 1);
		i = 0;
		while (i < 13 && table[i])
		{
			printf("---> %s\n", table[i]);
			i++;
		}
		free(str);
		if (init_all(table, scene))
			return (printf("Error\nObject initialization failed\n"), free_parsing_table(table), 1);
		free_parsing_table(table);
		str = get_next_line(fd);
		line++;
	}
	return (close(fd));
}*/

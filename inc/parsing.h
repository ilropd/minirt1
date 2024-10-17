/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:28:18 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/08 12:36:24 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structures.h"

# define TABLE_SIZE 13

/* parsing_gnl.c */
char	*get_token(char **table, int counter, char **str);
int		parse_string(char **table, char *str);
char	*grow_buffer(char *buffer, size_t new_size, int index);
char	*get_next_line(int fd);

/* parcing_scene.c */
int		open_file(char **argv);
int		process_line(char *str, t_scene *scene);
int		handle_error_cleanup(char *str, int fd, int line);
int		parsing_scene(char **argv, t_scene *scene);

/* parsing_table.c*/
void	free_parsing_table(char **table);
char	**parsing_table(void);

#endif

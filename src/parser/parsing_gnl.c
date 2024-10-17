/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:02:38 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/08 12:41:13 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

char	*get_token(char	**table, int counter, char **str)
{
	char	*start;
	char	*end;
	size_t	len;

	start = *str;
	while (ft_isspace(*start) || *start == ',')
		start++;
	if (*start == '\0')
		return (NULL);
	end = start;
	while (*end && !(ft_isspace(*end) || *end == ','))
		end++;
	len = end - start;
	*str = end;
	if (counter < 13)
	{
		table[counter] = (char *)malloc(len + 1);
		if (!table[counter])
			return (NULL);
		ft_strncpy(table[counter], start, len);
	}
	return (table[counter]);
}

int	parse_string(char **table, char *str)
{
	char		*token;
	int			counter;

	counter = 0;
	while (counter < 13)
	{
		token = get_token(table, counter, &str);
		if (token == NULL)
			break ;
		counter++;
	}
	if (counter >= 13)
		return (printf("Error\nWrong scene arguments\n"),
			free_parsing_table(table), 1);
	return (0);
}

char	*grow_buffer(char *buffer, size_t new_size, int index)
{
	char	*new_buffer;
	int		i;

	new_buffer = (char *)malloc(new_size + 1);
	if (!new_buffer)
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (i < index)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	int		index;
	int		bytes;
	char	*buffer;
	char	character;
	size_t	buffer_size;

	if (fd < 0)
		return (NULL);
	index = 0;
	bytes = read(fd, &character, 1);
	buffer_size = 1024;
	buffer = (char *)malloc(sizeof(char) * (buffer_size + 1));
	while (bytes > 0)
	{
		if (index >= (int)buffer_size)
			buffer = grow_buffer(buffer, buffer_size * 2, index);
		buffer[index++] = character;
		if (character == '\n')
			break ;
		bytes = read(fd, &character, 1);
	}
	if ((bytes <= 0) && (index == 0))
		return (free(buffer), NULL);
	buffer[index] = '\0';
	return (buffer);
}

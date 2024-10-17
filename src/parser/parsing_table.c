/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irozhkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:09:38 by irozhkov          #+#    #+#             */
/*   Updated: 2024/10/08 12:42:39 by irozhkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"

void	free_parsing_table(char **table)
{
	int	i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		if (table[i] != NULL)
			free(table[i]);
		i++;
	}
	free(table);
}

char	**parsing_table(void)
{
	char	**table;
	int		i;

	i = 0;
	table = (char **)malloc(TABLE_SIZE * sizeof(char *));
	if (!table)
		return (printf("Error\nCreation of parsing table failed\n"), NULL);
	while (i < TABLE_SIZE)
	{
		table[i] = NULL;
		i++;
	}
	return (table);
}

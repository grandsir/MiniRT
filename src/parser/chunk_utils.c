/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 02:16:57 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 10:34:20 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	chunk_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}

// returns copy of next chunk
char	*line_to_chunk(char *line)
{
	char	*chunk;
	size_t	len;

	line = skip_spaces(line);
	len = chunk_len(line);
	chunk = ft_substr(line, 0, len);
	return (chunk);
}

// returns start of next chunk
char	*find_next_chunk(char *line)
{
	line = skip_spaces(line);
	while (line && *line != ' ')
		line++;
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:46:39 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:05:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	count_rows(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	coordinate_to_vector(char *s, t_vector *vec4)
{
	float	x;
	float	y;
	float	z;
	char	**split;

	x = 0;
	y = 0;
	z = 0;
	split = ft_split(s, ',');
	if (!split || count_rows(split) != 3)
		return (EXIT_FAILURE);
	free(s);
	if (ctof(split[0], &x) || ctof(split[1], &y)
		|| ctof(split[2], &z))
		return (EXIT_FAILURE);
	free_arr(split);
	*vec4 = (t_vector){x, y, z, 0};
	return (EXIT_SUCCESS);
}


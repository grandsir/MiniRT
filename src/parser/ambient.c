/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:29:22 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:46:47 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ambient	*ambient_empty(void)
{
	t_ambient	*new;

	new = malloc(sizeof(t_ambient));
	if (!new)
		ft_error(10);
	new->color = (t_vector){0, 0, 0, 0};
	new->strength = 0;
	return (new);
}

t_ambient	*ambient_assign(char *line)
{
	t_ambient	*new;

	new = malloc(sizeof(t_ambient));
	if (!new)
		ft_error(10);
	line = read_float(line, &new->strength, 0, 1);
	line = read_vector(line, &new->color, 0, 255);
	new->color /= 255;
	new->color *= new->strength;
	return (new);
}

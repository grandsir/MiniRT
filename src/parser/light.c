/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:49:59 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:46:47 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_point_light	*point_light_empty(void)
{
	t_point_light	*new;

	new = malloc(sizeof(t_point_light));
	if (!new)
		ft_error(10);
	new->diff_color = (t_vector){0, 0, 0, 0};
	new->diff_power = 0;
	new->spec_color = (t_vector){0, 0, 0, 0};
	new->spec_power = 0;
	return (new);
}

t_point_light	*point_light_assign(char *line)
{
	t_point_light	*new;

	new = malloc(sizeof(t_point_light));
	if (!new)
		ft_error(10);
	line = read_vector(line, &new->position, 1, 0);
	line = read_float(line, &new->diff_power, 0, 1);
	line = read_vector(line, &new->diff_color, 0, 255);
	new->diff_color /= 255;
	new->spec_color = (t_vector){1, 1, 1, 1};
	new->spec_power = 1;
	return (new);
}

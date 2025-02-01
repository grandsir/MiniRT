/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:17:43 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:52:26 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_sphere	*parse_sphere(char *line, t_vector *color)
{
	t_sphere	*new;
	t_vector		c;

	new = malloc(sizeof(t_sphere));
	if (!new)
		ft_error(10);
	line = read_vector(line, &new->center, 1, 0);
	line = read_float(line, &new->radius, 1, 0);
	new->radius /= 2;
	line = read_vector(line, &c, 0, 255);
	*color = c / 255;
	return (new);
}

t_cyl	*parse_cyl(char *line, t_vector *color)
{
	t_cyl	*new;
	t_vector		c;

	new = malloc(sizeof(t_cyl));
	if (!new)
		ft_error(10);
	line = read_vector(line, &new->center, 1, 0);
	line = read_vector(line, &new->n, -1, 1);
	new->n = unit_vector(new->n);
	line = read_float(line, &new->radius, 1, 0);
	new->radius /= 2;
	line = read_float(line, &new->height, 1, 0);
	line = read_vector(line, &c, 0, 255);
	new->angle = angle(new->n, (t_vector){0, 1, 0});
	new->axis = unit_vector(cross(new->n, (t_vector){0, 1, 0}));
	*color = c / 255;
	return (new);
}

t_plane	*parse_plane(char *line, t_vector *color)
{
	t_plane	*new;
	t_vector	c;

	new = malloc(sizeof(t_plane));
	if (!new)
		ft_error(10);
	line = read_vector(line, &new->point, 1, 0);
	line = read_vector(line, &new->vector, -1, 1);
	new->vector = unit_vector(new->vector);
	line = read_vector(line, &c, 0, 255);
	*color = c / 255;
	return (new);
}

int	*object_assign(char *line, t_tokens t, t_object **objs)
{
	t_object	*node;
	t_vector			color;
	t_object	*tmp;

	node = NULL;
	if (t == SP)
		node = ft_objectnew(parse_sphere(line, &color),
				NULL, NULL, color);
	else if (t == PL)
		node = ft_objectnew(NULL, parse_plane(line, &color),
				NULL, color);
	else if (t == CY)
		node = ft_objectnew(NULL, NULL,
				parse_cyl(line, &color), color);
	tmp = *objs;
	ft_objectadd_back(&tmp, node);
	*objs = tmp;
	return (EXIT_SUCCESS);
}

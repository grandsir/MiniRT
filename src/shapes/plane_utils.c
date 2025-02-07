/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:20:01 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_plane	*plane_init(t_vector point, t_vector vector)
{
	t_plane	*p;

	p = malloc(sizeof(t_plane));
	if (!p)
		ft_error(10);
	p->point = point;
	p->vector = vector;
	return (p);
}

int	plane_hit(t_ray_hit hit, t_plane *p)
{
	float		denominator;
	float		t;
	t_vector	difference;

	denominator = dot_product(p->vector, hit.r->direction);
	if (fabs(denominator) < 0.0001)
		return (0);
	difference = p->point - hit.r->origin;
	t = dot_product(difference, p->vector) / denominator;
	if (t <= 0.0001)
		return (0);
	hit.res->n = p->vector;
	if (denominator > 0)
		hit.res->n = p->vector * -1;
	hit.res->p = ray_at(*hit.r, t);
	hit.res->t = t;
	set_face_normal(hit.res, *hit.r, p->vector);
	return (1);
}

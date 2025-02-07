/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:20:10 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:22:48 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"

float	cyl_infinite(t_ray_hit hit, t_cyl *cyl)
{
	t_simd_3	simd_3;
	t_ray		rray;
	float		t;
	float		y;

	rray.origin = hit.r->origin - cyl->center;
	rray.origin = rodrigues(rray.origin, cyl->axis, cyl->angle);
	rray.direction = rodrigues(hit.r->direction, cyl->axis, cyl->angle);
	simd_3.a = rray.direction[0] * rray.direction[0] + rray.direction[2]
		* rray.direction[2];
	simd_3.b = 2 * (rray.direction[0] * rray.origin[0] + rray.direction[2]
			* rray.origin[2]);
	simd_3.c = rray.origin[0] * rray.origin[0] + rray.origin[2] * rray.origin[2]
		- pow(cyl->radius, 2);
	t = quadratic(simd_3);
	if (t < 0)
		return (-1);
	y = rray.origin[1] + t * rray.direction[1];
	if (y < 0 || y > cyl->height)
		return (-1);
	return (t);
}

t_vector	cyl_center(t_cyl *cyl, t_vector point)
{
	float	x;

	x = dot_product(point - cyl->center, cyl->n);
	return (point - (x * cyl->n + cyl->center));
}

int	cyl_hit_shape(t_ray_hit hit, t_cyl *cyl)
{
	hit.res->t = cyl_infinite(hit, cyl);
	if (hit.res->t >= 0)
	{
		hit.res->p = ray_at(*hit.r, hit.res->t);
		hit.res->n = unit_vector(cyl_center(cyl, hit.res->p));
		if (length(cyl_center(cyl, hit.r->origin)) < cyl->radius)
			hit.res->n = (t_vector){0, 0, 0};
		return (1);
	}
	return (0);
}

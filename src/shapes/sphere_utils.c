/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:14:06 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

t_sphere	*sphere_init(t_vector center, float radius)
{
	t_sphere	*s;

	s = malloc(sizeof(t_sphere));
	if (!s)
		ft_error(10);
	s->center = center;
	s->radius = radius;
	return (s);
}

int	sphere_hit(t_ray_hit hit, t_sphere *s)
{
	t_vector	oc;
	t_simd_3	simd_3;
	float		discriminant;
	float		sqrtd;

	oc = hit.r->origin - s->center;
	simd_3.a = length_squared(hit.r->direction);
	simd_3.b = dot_product(oc, hit.r->direction);
	simd_3.c = length_squared(oc) - (s->radius * s->radius);
	discriminant = simd_3.b * simd_3.b - simd_3.a * simd_3.c;
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	hit.res->t = (-simd_3.b - sqrtd) / simd_3.a;
	if (hit.res->t < hit.t_min || hit.t_max < hit.res->t)
	{
		hit.res->t = (-simd_3.b + sqrtd) / simd_3.a;
		if (hit.res->t < hit.t_min || hit.t_max < hit.res->t)
			return (0);
	}
	hit.res->p = ray_at(*hit.r, hit.res->t);
	set_face_normal(hit.res, *hit.r, (hit.res->p - s->center) / s->radius);
	return (1);
}

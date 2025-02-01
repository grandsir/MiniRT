/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:12:50 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

t_lighting	get_point_light(t_point_light light,
	t_ray_hit hittable, t_object *world)
{
	t_lighting	l;
	t_vector		light_dir;
	float		distance;
	float		intensity;
	t_vector		h;

	l.diff = (t_vector){0, 0, 0, 0};
	l.spec = (t_vector){0, 0, 0, 0};
	l.if_s = 0;
	if (light.diff_power > 0)
	{
		light_dir = light.position - hittable.res->p;
		distance = length(light_dir);
		light_dir = unit_vector(light_dir);
		intensity = 4 * (float)clamp(dot_product(hittable.res->n, light_dir), 0, 1);
		l.diff = world->color * intensity * light.diff_color
			* light.diff_power / distance;
		h = unit_vector(-light_dir + hittable.r->direction);
		intensity = pow((float)dot_product(hittable.res->n, h), 120);
		l.spec = intensity * light.spec_color / distance;
		check_shadow(world, ray_init(light.position, -light_dir), &l);
	}
	return (l);
}

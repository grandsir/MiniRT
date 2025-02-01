/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:34:40 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:57:36 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_vector	ray_at(t_ray r, float t)
{
	return (r.origin + (t * r.direction));
}

t_ray	ray_init(t_vector o, t_vector d)
{
	t_ray	r;

	r.origin = o;
	r.direction = d;
	return (r);
}

t_ray	get_ray(t_camera cam, float i, float j, t_window win)
{
	float	u;
	float	v;

	u = ((float) i) / (win.width - 1);
	v = ((float) j) / (win.height - 1);
	return (ray_init(cam.origin, cam.btm_left_cnr
			+ (u * cam.horiz) + (v * cam.vert) - cam.origin));
}

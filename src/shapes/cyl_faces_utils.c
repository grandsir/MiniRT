/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl_faces_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:20:10 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:22:48 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyl.h"

int	cyl_cap_bottom(t_ray_hit hit, t_cyl *cyl)
{
	t_plane	*plane;

	plane = plane_init(cyl->center, cyl->n);
	if (plane_hit(hit, plane) && length(hit.res->p
			- plane->point) <= cyl->radius)
	{
		if (dot_product(hit.res->n, cyl->n) > 0)
			hit.res->n = (t_vector){0, 0, 0};
		free(plane);
		return (1);
	}
	free(plane);
	return (0);
}

int	cyl_cap_top(t_ray_hit hit, t_cyl *cyl)
{
	t_plane	*plane;

	plane = plane_init(cyl->center + (cyl->n * cyl->height), cyl->n);
	if (plane_hit(hit, plane) && length(hit.res->p
			- plane->point) <= cyl->radius)
	{
		if (dot_product(hit.res->n, cyl->n) < 0)
			hit.res->n = (t_vector){0, 0, 0};
		free(plane);
		return (1);
	}
	free(plane);
	return (0);
}

int	send_shape_cyl(t_ray_hit hit, t_cyl *cyl, int index)
{
	if (!cyl)
		return (0);
	if (index == 0)
		return (cyl_hit_shape(hit, cyl));
	if (index == 1)
		return (cyl_cap_top(hit, cyl));
	if (index == 2)
		return (cyl_cap_bottom(hit, cyl));
	return (0);
}

int	cyl_hittable(t_ray_hit hit, t_cyl *cyl)
{
	double	closest_so_far;
	int		i;
	int		closest_index;

	i = 0;
	closest_index = -1;
	closest_so_far = hit.t_max;
	while (i < 3)
	{
		if (send_shape_cyl(hit, cyl, i))
		{
			if (hit.res->t < closest_so_far)
			{
				closest_so_far = hit.res->t;
				closest_index = i;
			}
		}
		i++;
	}
	return (closest_index);
}

int	cyl_hit(t_ray_hit hit, t_cyl *cyl)
{
	int	index;

	index = cyl_hittable(hit, cyl);
	if (index == -1)
		return (0);
	return (send_shape_cyl(hit, cyl, index));
}

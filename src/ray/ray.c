/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 05:11:18 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:31 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	closest_obj(t_ray r, t_object *world, int *ret)
{
	int			i;
	int			j;
	t_ray_hit	hit;
	float		tmp_t;

	hit = ray_hit_init(&r, 0, INFINITY, hit_rec_init_empty());
	i = 0;
	j = 0;
	tmp_t = INFINITY;
	while (world)
	{
		if (hit_ray_hit_list(hit, world))
		{
			if (hit.res->t < tmp_t)
			{
				tmp_t = hit.res->t;
				i = j;
			}
			*ret = 1;
		}
		j++;
		world = world->next;
	}
	free(hit.res);
	return (i);
}

t_object	*find_world_touched_first(t_ray r, t_object *world)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = closest_obj(r, world, &ret);
	j = 0;
	while (i != 0 && world && j < i)
	{
		world = world->next;
		j++;
	}
	if (ret == 1)
		return (world);
	return (NULL);
}

t_vector	ray_color(t_ray r, t_global *elements)
{
	t_ray_hit	hit;
	t_lighting	lighting;
	t_object	*world;

	world = elements->objs;
	world = find_world_touched_first(r, world);
	hit = ray_hit_init(&r, 0, INFINITY, hit_rec_init_empty());
	if (world && hit_ray_hit_list(hit, world))
	{
		lighting = get_point_light(*elements->light, hit, world);
		free(hit.res);
		if (lighting.if_s == 1)
			return (world->color * elements->ambient->color);
		return ((world->color * elements->ambient->color) + lighting.diff
			+ lighting.spec);
	}
	free(hit.res);
	return ((t_vector){0, 0, 0, 0});
}

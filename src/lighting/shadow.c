/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:39:19 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

int	find_object_in_front(t_ray_hit light_hit, t_ray r, t_object *world)
{
	t_ray_hit	hit;
	float		tmp_t;
	t_object	*start;

	hit = ray_hit_init(&r, 0, INFINITY, hit_rec_init_empty());
	start = ft_objectlast(world);
	hit_ray_hit_list(light_hit, world);
	tmp_t = light_hit.res->t;
	while (start)
	{
		if (hit_ray_hit_list(hit, start))
		{
			if (hit.res->t < tmp_t)
			{
				free(hit.res);
				return (1);
			}
		}
		start = start->prev;
	}
	free(hit.res);
	return (0);
}

void	check_shadow(t_object *world, t_ray light_r, t_lighting *l)
{
	t_ray_hit	light_hit;

	light_hit = ray_hit_init(&light_r, 0, INFINITY, hit_rec_init_empty());
	if (find_object_in_front(light_hit, light_r, world))
		l->if_s = 1;
	free(light_hit.res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:25:43 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:49:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	send_shape(t_ray_hit hit, t_object *lst)
{
	if (!lst)
		return (0);
	if (lst->s)
		return (sphere_hit(hit, lst->s));
	else if (lst->p)
		return (plane_hit(hit, lst->p));
	else if (lst->c)
		return (cyl_hit(hit, lst->c));
	return (0);
}

int	hit_ray_hit_list(t_ray_hit hit, t_object *lst)
{
	t_hit_result	tmp_rec;
	int				hit_anything;
	double			closest_so_far;

	hit_anything = 0;
	closest_so_far = hit.t_max;
	if (send_shape(hit, lst))
	{
		hit_anything = 1;
		if (tmp_rec.t < closest_so_far)
			closest_so_far = tmp_rec.t;
		hit.res = &tmp_rec;
	}
	return (hit_anything);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 14:30:20 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:50:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_hit.h"

t_ray_hit	ray_hit_init(t_ray *r, float t_min, float t_max, t_hit_result *res)
{
	t_ray_hit	h;

	h.r = r;
	h.t_min = t_min;
	h.t_max = t_max;
	h.res = res;
	return (h);
}

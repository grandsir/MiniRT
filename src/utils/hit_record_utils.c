/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:14:48 by databey            #+#    #+#             */
/*   Updated: 2025/02/01 10:24:01 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_hit.h"

t_hit_result	*hit_rec_init_empty(void)
{
	t_hit_result	*res;

	res = malloc(sizeof(t_hit_result));
	if (!res)
		ft_error(10);
	res->p = (t_vector){0};
	res->n = (t_vector){0};
	res->t = 0;
	res->front_face = 0;
	return (res);
}

void	set_face_normal(t_hit_result *res, const t_ray r,
	const t_vector outward_normal)
{
	res->front_face = dot_product(r.direction, outward_normal) < 0;
	if (res->front_face)
		res->n = outward_normal;
	else
		res->n = -outward_normal;
}

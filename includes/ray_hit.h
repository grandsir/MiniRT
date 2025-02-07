/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:03:06 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:50:58 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_HIT_H
# define RAY_HIT_H
# include "minirt.h"
# include "ray.h"

typedef struct s_ray	t_ray;

typedef struct s_hit_result
{
	t_vector			p;
	t_vector			n;
	float				t;
	float				root2;
	int					front_face;
}						t_hit_result;

typedef struct s_ray_hit
{
	t_ray				*r;
	float				t_min;
	float				t_max;
	t_hit_result		*res;
}						t_ray_hit;

t_hit_result			*hit_rec_init_empty(void);
t_ray_hit				ray_hit_init(t_ray *r, float t_min, float t_max,
							t_hit_result *res);
void					set_face_normal(t_hit_result *res, const t_ray r,
							const t_vector outward_normal);

#endif
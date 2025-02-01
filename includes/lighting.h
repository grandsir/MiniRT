/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:03:06 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:49:09 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H
# include "minirt.h"

typedef float					t_vector __attribute__ ((vector_size (16)));
typedef struct s_ray_hit		t_ray_hit;
typedef struct s_rt_object		t_object;
typedef struct s_ray			t_ray;

typedef struct s_ambient
{
	float	strength;
	t_vector	color;
}	t_ambient;

typedef struct s_lighting
{
	t_vector	diff;
	t_vector	spec;
	int	if_s;
	t_vector	shadow;
}	t_lighting;

typedef struct s_point_light
{
	t_vector	position;
	t_vector	diff_color;
	float	diff_power;
	t_vector	spec_color;
	float	spec_power;
}	t_point_light;

t_point_light	point_light_init(t_vector	position, t_vector color, float power);
t_lighting		get_point_light(t_point_light light,
					t_ray_hit hittable, t_object *world);

//shadow
void			check_shadow(t_object *world,
					t_ray light_r, t_lighting *l);

#endif // LIGHTING_H
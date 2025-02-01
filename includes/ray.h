/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:33:04 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:31:46 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "minirt.h"

typedef float					t_vector __attribute__ ((vector_size (16)));
typedef struct s_ambient		t_ambient;
typedef struct s_point_light	t_point_light;
typedef struct s_global			t_global;
typedef struct s_rt_object		t_object;
typedef struct s_camera			t_camera;
typedef struct s_window			t_window;

typedef struct s_ray
{
	t_vector	origin;
	t_vector	direction;
}	t_ray;

t_vector		ray_at(t_ray r, float t);
t_ray			ray_init(t_vector o, t_vector d);
t_vector		ray_color(t_ray r, t_global *elements);
t_ray			get_ray(t_camera cam, float i, float j, t_window win);
t_object		*find_world_touched_first(t_ray r, t_object *world);

#endif
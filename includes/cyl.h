/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:21:25 by databey           #+#    #+#             */
/*   Updated: 2025/02/07 22:24:35 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYL_H
# define CYL_H
# include "minirt.h"

typedef float				t_vector __attribute__((vector_size(16)));

typedef struct s_cyl
{
	t_vector			center;
	t_vector			n;
	float				radius;
	float				height;
	float				angle;
	t_vector			axis;
}						t_cyl;

t_vector				cyl_center(t_cyl *cyl, t_vector point);
float					cyl_infinite(t_ray_hit hit, t_cyl *cyl);
int						send_shape_cyl(t_ray_hit hit, t_cyl *cyl, int index);
int						cyl_cap_bottom(t_ray_hit hit, t_cyl *cyl);
int						cyl_cap_top(t_ray_hit hit, t_cyl *cyl);
int						cyl_hit_shape(t_ray_hit hit, t_cyl *cyl);
int						cyl_hittable(t_ray_hit hit, t_cyl *cyl);
int						cyl_hit(t_ray_hit hit, t_cyl *cyl);

#endif
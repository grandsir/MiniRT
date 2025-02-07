/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 00:31:04 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:51:52 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "minirt.h"
# include "ray_hit.h"

typedef struct s_ray_hit	t_ray_hit;

typedef struct s_sphere
{
	t_vector				center;
	float					radius;
}							t_sphere;

t_sphere					*sphere_init(t_vector center, float radius);
int							sphere_hit(t_ray_hit hit, t_sphere *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:35:12 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:36:35 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	rodrigues(t_vector v, t_vector axis, float angle)
{
	if (angle == 0 || angle == 3.141592653589f)
		return (v);
	return (v * cosf(angle)
		+ cross(axis, v) * sinf(angle)
		+ axis * dot_product(axis, v) * (1 - cosf(angle)));
}

float	quadratic(t_simd_3 simd_3)
{
	float	delta;
	float	t;
	float	t2;


	delta = pow(simd_3.b, 2) - 4 * simd_3.a * simd_3.c;
	if (delta < 0)
		return (-1);
	t = (-simd_3.b - sqrt(delta)) / (2 * simd_3.a);
	t2 = (-simd_3.b + sqrt(delta)) / (2 * simd_3.a);
	if ((t2 < t && t2 >= 0) || t < 0)
		t = t2;
	return (t);
}

float	angle(t_vector v, t_vector u)
{
	return (acos(dot_product(v, u)) / (length(v) * length(u)));
}

t_vector	project(t_vector v, t_vector u)
{
	return (u * (dot_product(u, v)) / dot_product(v, u));
}

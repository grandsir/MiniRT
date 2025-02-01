/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 12:12:01 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:20:18 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	dot_product(const t_vector x, const t_vector y)
{
	return (x[0] * y[0]
		+ x[1] * y[1]
		+ x[2] * y[2]);
}

float	length_squared(t_vector x)
{
	return (x[0] * x[0] + x[1] * x[1] + x[2] * x[2]);
}

float	length(t_vector x)
{
	return (sqrt(length_squared(x)));
}

t_vector	unit_vector(t_vector x)
{
	return (x / length(x));
}

t_vector	cross(const t_vector x, const t_vector y)
{
	t_vector	z;

	z[0] = x[1] * y[2] - x[2] * y[1];
	z[1] = x[2] * y[0] - x[0] * y[2];
	z[2] = x[0] * y[1] - x[1] * y[0];
	z[3] = 0;
	return (z);
}
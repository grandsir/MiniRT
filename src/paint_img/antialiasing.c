/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antialiasing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 07:32:14 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:56:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	antialiasing(int i, int j, t_global elements, t_window win)
{
	float		s;
	float		t;
	t_vector	color;

	s = 0.1;
	while (s < 1)
	{
		t = 0.1;
		while (t < 1)
		{
			color = color + ray_color(get_ray(*elements.cam, i + s, j + t, win),
					&elements);
			t += 0.1;
		}
		s += 0.1;
	}
	color *= (float)0.01;
	return (color);
}

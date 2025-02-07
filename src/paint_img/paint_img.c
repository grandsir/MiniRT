/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:12:25 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:56:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	paint_img(t_window win, t_global elements)
{
	int			j;
	int			i;
	t_vector	color;

	j = 0;
	while (j < win.height)
	{
		i = 0;
		while (i < win.width)
		{
			if (ANTI == 1)
				color = antialiasing(i, j, elements, win);
			else
				color = ray_color(get_ray(*elements.cam, i, j, win), &elements);
			write_color(color, i, j, win);
			i++;
		}
		j++;
	}
}

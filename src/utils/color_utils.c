/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 17:12:16 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:56:49 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	write_color(t_vector color, int x, int y, t_window win)
{
	int	ir;
	int	ig;
	int	ib;

	ir = (int)(255.99 * clamp(color[0], 0, 0.999));
	ig = (int)(255.99 * clamp(color[1], 0, 0.999));
	ib = (int)(255.99 * clamp(color[2], 0, 0.999));
	mlx_put_pixel(win.img, x, win.height - y - 1, create_rgba(ir, ig, ib, 255));
}

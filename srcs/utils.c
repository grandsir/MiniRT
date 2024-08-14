/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:49:32 by databey           #+#    #+#             */
/*   Updated: 2024/08/14 18:59:28 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		setup_global(void *mlx, void *mlx_win, t_global *g)
{
	g->img = NULL;
	g->angle.a = 0.0f;
	g->angle.b = 0.0f;
	g->angle.c = 0.0f;
	g->mlx = mlx;
	g->mlx_win = mlx_win;
}

void	mlx_safe_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

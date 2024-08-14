/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:46:31 by databey           #+#    #+#             */
/*   Updated: 2024/08/14 18:57:22 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/includes/libft.h"
# include "actions.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define SCREEN_WIDTH 1080.0f
# define SCREEN_HEIGHT 720.0f

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point_2d
{
	int		x;
	int		y;
}			t_point_2d;

typedef struct s_angle_3d
{
	double		a;
	double		b;
	double		c;
}			t_angle_3d;

typedef struct s_point_3d
{
	double		x;
	double		y;
	double		z;
}			t_point_3d;

typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	t_angle_3d angle;
}			t_global;

void		setup_global(void *mlx, void *mlx_win, t_global *g);
void		mlx_safe_pixel_put(t_data *data, int x, int y, int color);
void		init_image(t_global *g);
void		print_cube(t_global *g);
void		print_pixel(t_global *g, double x, double y, double z, int color);

#endif

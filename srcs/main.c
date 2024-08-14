/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:50:37 by databey           #+#    #+#             */
/*   Updated: 2024/08/14 19:28:46 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

double calculate_rotated_x(t_angle_3d angle, t_point_3d point)
{
	return (cos(angle.c) * (point.x * cos(angle.b) - sin(angle.b) * 
	(point.z * cos(angle.a) - point.y * sin(angle.a))) 
	+ sin(angle.c) * (point.y * cos(angle.a) + point.z * sin(angle.a)));
}

double calculate_rotated_y(t_angle_3d angle, t_point_3d point)
{
	return (cos(angle.c) * (point.y * cos(angle.a) + point.z * sin(angle.a)) - sin(angle.c) * 
	(point.x * cos(angle.b) - sin(angle.b) * (point.z * cos(angle.a) - point.y * sin(angle.a)))
	);
}

double calculate_rotated_z(t_angle_3d angle, t_point_3d point)
{
	return ((point.x * sin(angle.b) + cos(angle.b)) * (point.z * cos(angle.a) - point.y * sin(angle.a)));
}

void	clear_image_memory(t_global *g)
{
    if (g->img->img)
        mlx_destroy_image(g->mlx, g->img->img);
    if (g->img)
        free(g->img);
}

void	init_image(t_global *g)
{
	t_data	*img;

	if (g->img)
		clear_image_memory(g);
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(g->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	g->img = img;
}


static int	on_frame_update(t_global *g)
{
	init_image(g);
	mlx_clear_window(g->mlx, g->mlx_win);
	print_cube(g);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->img->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_global	g;
	t_angle_3d	angle;

	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "RTX 2023");
	if (mlx_win == NULL)
	{
		free(mlx);
		return (0);
	}
	setup_global(mlx, mlx_win, &g);
	// if (handle_arg(&g, argc, argv) == 1)
	// 	return (1);
	mlx_loop_hook(mlx, on_frame_update, &g);
	mlx_loop(mlx);
	return (0);
}

void print_cube(t_global *g)
{
	double speed = 1.0f;
	double size = 250.0f;
	int color = 0xA020F0;
	t_point_2d point;

	point.x = -size;
	point.y = -size;
	while(point.x < size)
	{
		while(point.y < size)
		{
			point.x += SCREEN_WIDTH / 2;
			point.y += SCREEN_HEIGHT / 2;
			print_pixel(g, point.x, point.y, -size, color);
			print_pixel(g, size, point.y, point.x, color);
			print_pixel(g, -size, point.y, -point.x, color);
			print_pixel(g, -point.x, point.y, size, color);
			point.y += speed;
		}
		point.x += speed;
	}
	g->angle.a += 0.01f;
	g->angle.b += 0.01f;
	g->angle.c += 0.01f;
}

void print_pixel(t_global *g, double x, double y, double z, int color)
{
	double rotated_x;
	double rotated_y;
	double rotated_z;

	int coordinate_x;
	int coordinate_y;
	
	t_point_3d point;

	double distance = 50.0f;

	point.x = x;
	point.y = y;
	point.z = z;
	
	rotated_x = calculate_rotated_x(g->angle, point);
	rotated_y = calculate_rotated_y(g->angle, point);
	rotated_z = calculate_rotated_z(g->angle, point);

	coordinate_x = (int)(rotated_x / rotated_z);
	coordinate_y = (int)(rotated_y / rotated_z);

	mlx_safe_pixel_put(g->img, coordinate_x, coordinate_y, color);
}
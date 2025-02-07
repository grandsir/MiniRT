/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muyucego <muyucego@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:03:06 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/07 22:27:20 by muyucego         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include "cyl.h"
# include "error.h"
# include "lighting.h"
# include "objects.h"
# include "parser.h"
# include "plane.h"
# include "ray.h"
# include "ray_hit.h"
# include "sphere.h"
# include <fcntl.h>
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ASPECT_RATIO 1.7777777778
# define WIDTH 1200

typedef float t_vector			__attribute__((vector_size(16)));
typedef struct s_ray			t_ray;
typedef enum s_tokens			t_tokens;
typedef struct s_global			t_global;
typedef struct s_camera			t_camera;
typedef struct s_ambient		t_ambient;
typedef struct s_lighting		t_lighting;
typedef struct s_point_light	t_point_light;

typedef struct s_global
{
	t_ambient					*ambient;
	t_camera					*cam;
	t_point_light				*light;
	t_object					*objs;
}								t_global;

typedef struct s_window
{
	int							height;
	int							width;
	mlx_image_t					*img;
}								t_window;

typedef struct s_camera
{
	t_vector					origin;
	t_vector					horiz;
	t_vector					vert;
	t_vector					btm_left_cnr;
}								t_camera;

typedef enum s_tokens
{
	A = 1,
	C,
	L,
	SP,
	PL,
	CY
}								t_tokens;

typedef struct s_thread_data
{
	int							i;
	int							j;
	t_global					elements;
	t_window					win;
	t_vector					color;
}								t_thread_data;

typedef struct s_simd_3
{
	float						a;
	float						b;
	float						c;
}								t_simd_3;

t_global						elements_init_empty(void);
t_vector						cross(const t_vector u, const t_vector v);
t_vector						unit_vector(t_vector v);
t_vector						rodrigues(t_vector v, t_vector axis,
									float angle);
t_vector						project(t_vector v, t_vector u);
t_vector						antialiasing(int i, int j, t_global elements,
									t_window win);
float							deg_to_rad(float deg);
float							clamp(float x, float min, float max);
float							length_squared(t_vector v);
float							length(t_vector v);
float							dot_product(const t_vector u, const t_vector v);
float							hit_sphere(t_sphere *s, t_ray r);
float							angle(t_vector v, t_vector u);
float							quadratic(t_simd_3 simd_3);
void							paint_img(t_window win, t_global elements);
void							create_painters(t_window win,
									t_global elements);
void							write_color(t_vector color, int x, int y,
									t_window win);
void							create_painters(t_window win,
									t_global elements);
void							write_color(t_vector color, int x, int y,
									t_window win);
int								ctof(char *s, float *f);
int								hit_ray_hit_list(t_ray_hit hit, t_object *lst);
int								plane_hit(t_ray_hit hit, t_plane *p);
int								cyl_hit(t_ray_hit hit, t_cyl *cyl);

#endif
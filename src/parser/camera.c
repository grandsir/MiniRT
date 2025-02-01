/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:31:52 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:57:29 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_camera	cam_init(t_vector look_from, t_vector n, float fov)
{
	t_camera	cam;
	t_vector	up;
	t_vector	right;
	float	vp_h;
	float	vp_w;

	up = (t_vector){0, 1, 0};
	if (n[0] == 0 && n[2] == 0)
		up = (t_vector){0, 0, 1};
	vp_w = tan(deg_to_rad(fov) / 2);
	vp_h = (vp_w / ASPECT_RATIO);
	right = unit_vector(cross(up, n));
	cam.origin = look_from;
	cam.horiz = right * vp_w;
	cam.vert = vp_h * up;
	cam.btm_left_cnr = cam.origin - cam.horiz / 2
		- cam.vert / 2 + n;
	return (cam);
}

t_camera	*cam_assign(char *line)
{
	t_camera	*new;
	t_vector	look_from;
	t_vector	n;
	float	fov;

	new = malloc(sizeof(t_camera));
	line = read_vector(line, &look_from, 1, 0);
	line = read_vector(line, &n, -1, 1);
	line = read_float(line, &fov, 0, 180);
	n = unit_vector(n);
	*new = cam_init(look_from, n, fov);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 06:21:14 by muyucego          #+#    #+#             */
/*   Updated: 2025/02/01 13:31:27 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "minirt.h"

typedef struct s_plane
{
	t_vector	point;
	t_vector	vector;
}				t_plane;

t_plane			*plane_init(t_vector point, t_vector vector);

#endif
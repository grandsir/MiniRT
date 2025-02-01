/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 15:41:52 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:51:43 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "minirt.h"
# include "ray_hit.h"

typedef float				t_vector __attribute__ ((vector_size (16)));
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cyl		t_cyl;
typedef struct s_ray_hit	t_ray_hit;

typedef struct s_rt_object
{
	t_sphere			*s;
	t_plane				*p;
	t_cyl				*c;
	t_ray_hit			*hit;
	t_vector			color;
	int					i;
	struct s_rt_object	*next;
	struct s_rt_object	*prev;
}	t_object;

t_object	*ft_objectnew(t_sphere *s, t_plane *p,
					t_cyl *c, t_vector color);
void		ft_objectadd_back(t_object **lst,
					t_object *new);
void		ft_object_rm_first(t_object **lst);
void		ft_objectclear(t_object **lst);
t_object	*ft_objectfirst(t_object *map);
t_object	*ft_objectlast(t_object *map);

#endif
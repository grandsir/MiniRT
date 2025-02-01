/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:34:29 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:22:48 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

t_point_light	point_light_init(t_vector position, t_vector color, float power)
{
	t_point_light	node;

	node.position = position;
	node.diff_color = color;
	node.diff_power = power;
	node.spec_color = (t_vector){1, 1, 1, 1};
	node.spec_power = 2;
	return (node);
}

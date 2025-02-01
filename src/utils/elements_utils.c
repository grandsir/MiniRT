/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:12:12 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:28:17 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_global	elements_init_empty(void)
{
	t_global	new;

	new.ambient = NULL;
	new.cam = NULL;
	new.light = NULL;
	new.objs = NULL;
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:23:42 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:52:26 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*ft_objectnew(t_sphere *s, t_plane *p,
	t_cyl *c, t_vector color)
{
	t_object	*new_element;
	static int		i = 0;

	new_element = (t_object *)malloc(sizeof(t_object));
	if (!new_element)
		return (0);
	new_element->s = s;
	new_element->p = p;
	new_element->c = c;
	new_element->color = color;
	new_element->i = i++;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_objectadd_back(t_object **lst, t_object *new)
{
	t_object	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

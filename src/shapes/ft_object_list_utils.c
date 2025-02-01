/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:23:42 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 12:50:58 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

void	ft_object_rm_first(t_object **lst)
{
	t_object	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
}

void	ft_objectclear(t_object **lst)
{
	t_object	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		if ((*lst)->c)
			free((*lst)->c);
		if ((*lst)->s)
			free((*lst)->s);
		if ((*lst)->p)
			free((*lst)->p);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_object	*ft_objectfirst(t_object *map)
{
	if (!map)
		return (NULL);
	while (map->prev != NULL)
		map = map->prev;
	return (map);
}

t_object	*ft_objectlast(t_object *map)
{
	if (!map)
		return (NULL);
	while (map->next != NULL)
		map = map->next;
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:23:17 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 11:49:36 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	assign_element(char *line, t_tokens t, t_global *element)
{
	if (t == A)
	{
		if (element->ambient == NULL)
			element->ambient = ambient_assign(line);
		else
			ft_error_str(21, "An ambient light");
	}
	else if (t == C)
	{
		if (element->cam == NULL)
			element->cam = cam_assign(line);
		else
			ft_error_str(21, "A camera");
	}
	else if (t == L)
	{
		if (element->light == NULL)
			element->light = point_light_assign(line);
		else
			ft_error_str(21, "A light");
	}
	else if (t == SP || t == PL || t == CY)
		object_assign(line, t, &element->objs);
}

void	check_elements(t_global *elements)
{
	if (elements->cam == NULL)
		ft_error(5);
	if (elements->ambient == NULL)
	{
		elements->ambient = ambient_empty();
		ft_printf("The rt file does not include an ambient light.\n");
	}
	if (elements->light == NULL)
	{
		elements->light = point_light_empty();
		ft_printf("The rt file does not include a light.\n");
	}
	if (elements->objs == NULL)
		ft_printf("The rt file does not include objects.\n");
}

t_global	parse_input(char *file)
{
	t_global	elements;
	char		*line;
	int			fd;

	check_file_type(file);
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_error(1);
	elements = elements_init_empty();
	while (line)
	{
		if (ft_strncmp(line, "\n", ft_strlen(line)))
			assign_element(line, return_type(line_to_chunk(line)), &elements);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	check_elements(&elements);
	return (elements);
}

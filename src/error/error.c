/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 02:04:44 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 10:37:01 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_error_str(int i, char *str)
{
	ft_printf("Error\n");
	if (i == 21)
		ft_printf("%s can only be declared once in the scene.\n", str);
	if (i == 1)
		ft_printf("Vec3 conversion impossible near line: '%s'\n", str);
	if (i == 2)
		ft_printf("Float conversion impossible near line: '%s'\n", str);
	if (i == 3)
		ft_printf("Float is out of range near line: '%s'\n", str);
	if (i == 4)
		ft_printf("Vec3 is out of range near line: '%s'\n", str);
	if (i == 5)
		ft_printf("%s is not an existing element.\n", str);
	exit(EXIT_FAILURE);
}

void	ft_error(int i)
{
	ft_printf("Error\n");
	if (i == 0)
		ft_printf("Incorrect file type\n");
	if (i == 1)
		ft_printf("Empty file\n");
	if (i == 2)
		ft_printf(" is not an existing element.\n");
	if (i == 3)
		ft_printf("Out of range.\n");
	if (i == 4)
		ft_printf("Incomplete line\n");
	if (i == 5)
		ft_printf("The rt file does not include a camera.\n");
	if (i == 10)
		ft_printf("MALLOC ERROR\n");
	if (i == 20)
		ft_printf("No input\n");
	exit(EXIT_FAILURE);
}

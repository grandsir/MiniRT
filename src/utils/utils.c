/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:54:49 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 10:26:40 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ctof_dec(char *s, double *d)
{
	float	f;
	float	mul;

	f = 0;
	mul = 1;
	while (ft_isdigit(*s))
	{
		mul /= 10;
		f = f * 10 + (*s - '0');
		s++;
	}
	if (*s)
		return (EXIT_FAILURE);
	*d += f * mul;
	return (EXIT_SUCCESS);
}

int	ctof(char *s, float *f)
{
	float	sign;
	double	d;

	d = 0;
	sign = 1;
	if (!s)
		return (EXIT_FAILURE);
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	if (!ft_isdigit(*s))
		return (EXIT_FAILURE);
	while (ft_isdigit(*s) && (d < FLT_MAX || d > FLT_MIN))
	{
		d = d * 10 + (*s - '0');
		s++;
	}
	if (*s == '.' && ctof_dec(++s, &d) && *s)
		return (EXIT_FAILURE);
	*f = d * sign;
	return (EXIT_SUCCESS);
}

float	deg_to_rad(float deg)
{
	return (deg * M_PI / 180);
}

float	clamp(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

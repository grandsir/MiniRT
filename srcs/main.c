/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:50:37 by databey           #+#    #+#             */
/*   Updated: 2024/08/04 19:51:15 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char *argv[])
{
	void		*mlx;
	void		*mlx_win;
	t_global	g;

	mlx = mlx_init();
	if (mlx == NULL)
		return (0);
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Fractol");
	if (mlx_win == NULL)
	{
		free(mlx);
		return (0);
	}
	setup_global(mlx, mlx_win, &g);
	// if (handle_arg(&g, argc, argv) == 1)
	// 	return (1);
	mlx_loop(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:12:01 by databey           #+#    #+#             */
/*   Updated: 2025/02/01 13:57:10 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_window	setup_win(mlx_t **mlx)
{
	t_window	win;

	win.width = WIDTH;
	win.height = (int)(win.width / ASPECT_RATIO);
	*mlx = mlx_init(win.width, win.height, "miniRT", 1);
	win.img = mlx_new_image(*mlx, win.width, win.height);
	return (win);
}

void	_mlx_keypress(keys_t key)
{
	if (key == MLX_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
}

void	free_elements(t_global *elements)
{
	if (elements->ambient)
		free(elements->ambient);
	free(elements->cam);
	if (elements->light)
		free(elements->light);
	ft_objectclear(&elements->objs);
}

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	t_window			win;
	t_global		elements;

	if (argc < 2)
		ft_error(20);
	elements = parse_input(argv[1]);
	win = setup_win(&mlx);
	paint_img(win, elements);
	mlx_image_to_window(mlx, win.img, 0, 0);
	mlx_key_hook(mlx, (mlx_keyfunc)_mlx_keypress, mlx);
	free_elements(&elements);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

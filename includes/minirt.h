/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:46:31 by databey           #+#    #+#             */
/*   Updated: 2024/08/04 19:50:10 by databey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/includes/libft.h"
# include "actions.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# define SCREEN_WIDTH 1920.0f
# define SCREEN_HEIGHT 1080.0f

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_global
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
}			t_global;

void		setup_global(void *mlx, void *mlx_win, t_global *g);

#endif

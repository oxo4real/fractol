/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:26:49 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/07 20:49:55 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal);
static void	events_init(t_fractal *fractal);

void	init_fractal(t_fractal *fractal)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		print_error("malloc");
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										SIZE, SIZE, fractal->name);
	if (!fractal->mlx_window)
		return (free(fractal->mlx_connection), print_error("malloc"));
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection,
										SIZE, SIZE);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		return (free(fractal->mlx_connection), print_error("malloc"));
	}
	fractal->img.px_ptr = mlx_get_data_addr(fractal->img.img_ptr,
											&fractal->img.bpp,
											&fractal->img.line_len,
											&fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window,
			ON_KEYDOWN,
			0,
			key_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			ON_MOUSEDOWN,
			0,
			mouse_handler,
			fractal);
	mlx_hook(fractal->mlx_window,
			ON_DESTROY,
			0,
			close_handler,
			fractal);
	//mlx_hook(fractal->mlx_window,
	//		ON_MOUSEMOVE,
	//		0,
	//		julia_track,
	//		fractal);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escaped = 4;
	fractal->definition = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

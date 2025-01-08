/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:55:35 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 07:56:42 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	compute_pixel(t_fractal *fractal, int x, int y);
static void	ft_put_pixel(int x, int y, t_img *img, int color);

void	ft_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			compute_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
							fractal->mlx_window,
							fractal->img.img_ptr,
							0, 0);
}

static void	compute_pixel(t_fractal *fractal, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.r = 0.0;
	z.i = 0.0;
	c.r = (ft_map(x, -2, +0.5, SIZE) * fractal->zoom) + fractal->shift_x;
	c.i = (ft_map(y, +1.25, -1.25, SIZE) * fractal->zoom) + fractal->shift_y;
	i = 0;
	while (i < fractal->definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.i * z.i) + (z.r * z.r) > fractal->escaped)
		{
			color = ft_map(i, DODGER_BLUE, BRIGHT_YELLOW, fractal->definition);
			return (ft_put_pixel(x, y, &fractal->img, color));
		}
		i++;
	}
	ft_put_pixel(x, y, &fractal->img, 0);
}

static void	ft_put_pixel(int x, int y, t_img *img, int color)
{
	int		offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->px_ptr + offset) = color;
}

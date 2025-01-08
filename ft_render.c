/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:55:35 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:59:29 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	compute_pixel(t_fractal *fractal, int x, int y);
static void	ft_put_pixel(int x, int y, t_img *img, int color);
static void	set_c(t_complex *z, t_complex *c, t_fractal *fractal);

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

	z.r = (ft_map(x, -2, +2, SIZE) * fractal->zoom) + fractal->shift_x;
	z.i = (ft_map(y, +2, -2, SIZE) * fractal->zoom) + fractal->shift_y;
	set_c(&z, &c, fractal);
	i = 0;
	while (i < fractal->definition)
	{
		z = sum_complex(power_complex(z, fractal->pow), c);
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

static void	set_c(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (ft_strcmp(fractal->name, "julia") == 0)
	{
		c->r = fractal->julia_r;
		c->i = fractal->julia_i;
	}
	else
	{
		c->r = z->r;
		c->i = z->i;
	}
}

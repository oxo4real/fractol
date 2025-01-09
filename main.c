/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:30:06 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:59:51 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	print_options(void);

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0) || (ac == 4
			&& ft_strcmp(av[1], "julia") == 0))
	{
		fractal.name = av[1];
		if (ft_strcmp(av[1], "mandelbrot") == 0)
			fractal.pow = 2;
		else if (ft_strcmp(av[1], "julia") == 0)
		{
			fractal.pow = 2;
			fractal.julia_r = ft_atodbl(av[2]);
			fractal.julia_i = ft_atodbl(av[3]);
		}
		init_fractal(&fractal);
		ft_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		print_options();
}

static void	print_options(void)
{
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("   ./fractol mandelbrot\n", 1);
	ft_putstr_fd("   ./fractol julia <real> <imaginary>\n", 1);
}

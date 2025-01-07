/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:30:06 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/04 20:48:13 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_options(void)
{
	ft_putstr_fd("Options:\n", 1);
	ft_putstr_fd("   ./fractol mandelbrot\n", 1);
	ft_putstr_fd("   ./fractol julia <value_1> <value_2>\n", 1);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		|| (ac == 4 && ft_strcmp(av[1], "julia") == 0))
	{
		fractal.name = av[1];
		init_fractal(&fractal);
		ft_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
		print_options();
}

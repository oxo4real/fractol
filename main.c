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

int	main(int ac, char **av)
{
	if (ac == 2 && ft_strcmp(av[1], "mandelbrot") == 0)
		ft_putstr_fd("success!\n", 1);
		// ft_mandelbrot();
	else
	{
	 	ft_putstr_fd("Options:\n", 1);
		ft_putstr_fd("   ./fractol mandelbrot\n", 1);
		ft_putstr_fd("   ./fractol julia <value_1> <value_2>\n", 1);
	}
}

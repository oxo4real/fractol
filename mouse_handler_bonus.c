/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:42:18 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:59:55 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	old_x;
	double	old_y;

	old_x = ft_map(x, -2, +2, SIZE) * fractal->zoom;
	old_y = ft_map(y, +2, -2, SIZE) * fractal->zoom;
	if (button == 4)
	{
		fractal->zoom *= 0.85;
		fractal->shift_x += (old_x - ft_map(x, -2, +2, SIZE)
				* fractal->zoom);
		fractal->shift_y += (old_y - ft_map(y, +2, -2, SIZE)
				* fractal->zoom);
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.15;
		fractal->shift_x += (old_x - ft_map(x, -2, +2, SIZE)
				* fractal->zoom);
		fractal->shift_y += (old_y - ft_map(y, +2, -2, SIZE)
				* fractal->zoom);
	}
	else
		return (0);
	ft_render(fractal);
	return (0);
}

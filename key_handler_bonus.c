/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:58:41 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 14:58:43 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		close_handler(fractal);
	else if (keysym == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 69)
		fractal->definition += 10;
	else if (keysym == 78)
		fractal->definition -= 10;
	else
		return (0);
	ft_render(fractal);
	return (0);
}

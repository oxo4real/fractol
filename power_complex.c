/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:10:32 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:10:32 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static t_complex	multiply_complex(t_complex a, t_complex b);

t_complex	power_complex(t_complex z, int n)
{
	t_complex	result;
	t_complex	base;

	base = z;
	result.r = 1;
	result.i = 0;
	if (n == 0)
		return (result);
	while (n > 0)
	{
		if (n % 2 == 1)
			result = multiply_complex(result, base);
		base = multiply_complex(base, base);
		n /= 2;
	}
	return (result);
}

static t_complex	multiply_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.r = (a.r * b.r) - (a.i * b.i);
	result.i = (a.r * b.i) + (a.i * b.r);
	return (result);
}

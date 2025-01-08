/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_complex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:24:40 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:24:40 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.r = z1.r + z2.r;
	sum.i = z1.i + z2.i;
	return (sum);
}

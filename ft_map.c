/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:18:35 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/08 12:59:11 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_map(double unscaled, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * unscaled / old_max + new_min);
}

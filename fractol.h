/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghzal <aaghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:22:16 by aaghzal           #+#    #+#             */
/*   Updated: 2025/01/04 20:42:46 by aaghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include <mlx.h>
# include <unistd.h>

typedef struct s_img
{
	void			*img_ptr;
	unsigned char	*px_ptr;
	int				bpp;
	int				endian;
	int				line_len;
}				t_img;

typedef struct s_fractal
{
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
}				t_fractal;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

double		ft_atodbl(char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif

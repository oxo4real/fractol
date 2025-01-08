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

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define SIZE 500

typedef struct s_img
{
	void	*img_ptr;
	char	*px_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	double	escaped;
	int		definition;
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_r;
	double	julia_i;
	double	pow;
}				t_fractal;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

# define DODGER_BLUE 0x00008B
# define BRIGHT_YELLOW 0xFFD700

double		ft_atodbl(char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);
t_complex	sum_complex(t_complex z1, t_complex z2);
void		print_error(char *s);
void		init_fractal(t_fractal *fractal);
void		ft_render(t_fractal *fractal);
double		ft_map(double unscaled, double new_min,
				double new_max, double old_max);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
t_complex	power_complex(t_complex z, int n);
int			ft_atoi(char *str);

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

#endif

#include "fractol.h"

t_complex	square_complex(t_complex z)
{
	t_complex	square;

	square.r = (z.r * z.r) + (z.i * z.i);
	square.i = 2 * z.r * z.i;
	return (square);
}

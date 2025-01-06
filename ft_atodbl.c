#include "fractol.h"

double	ft_atodbl(char *s)
{
	int			sign;
	long long	int_part;
	double		frac_part;
	double		power;

	int_part = 0;
	frac_part = 0;
	sign = 1;
	power = 1;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
		if (*(s++) == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9')
		int_part = (int_part * 10) + (*(s++) - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		power /= 10;
		frac_part = frac_part + (*(s++) - '0') * power;
	}
	return ((int_part + frac_part) * sign);
}

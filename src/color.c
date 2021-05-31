#include "../inc/fractol.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	ft_choose_color(t_all *all, int i)
{
	all->r = sin(all->freq * i + 0) * 128 + 127;
	all->g = sin(all->freq * i + 2) * 128 + 127;
	all->b = sin(all->freq * i + 4) * 128 + 127;
	all->color = encode_rgb(all->r, all->g, all->b);
}

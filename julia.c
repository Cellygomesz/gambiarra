/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:35 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/14 11:54:50 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	iterate_julia(t_f *f, t_complex *c, double c_re, double c_im)
{
	int		iter;
	double	tmp;

	iter = 0;
	tmp = 0;
	while (c->cx * c->cx + c->cy * c->cy <= 4 && iter < f->max_iter)
	{
		tmp = c->cx * c->cx - c->cy * c->cy + c_re - c->form1;
		c->cy = 2 * c->cx * c->cy + c_im + c->form2;
		c->cx = tmp;
		iter++;
	}
	return (iter);
}

void	julia_set(t_f *f)
{
	int			x;
	int			y;
	t_complex	complex;

	y = 0;
	while (y < 700)
	{
		x = 0;
		while (x < 950)
		{
			complex = map_to_complex_plane(f, x, y);
			color_pixel(f, x, y, 0xff4a92 * f->zoom_level * \
					iterate_julia(f, &complex, f->c_re, f->c_im));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	julia(t_f *f)
{
	if (!f)
		exit(1);
	f->mlx = mlx_init();
	init_julia(f);
	f->win = mlx_new_window(f->mlx, 950, 700, "Julia");
	num_julia(f, f->max_iter);
	julia_set(f);
	mlx_key_hook(f->win, key_esc, NULL);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0, close_win, f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_loop(f->mlx);
}

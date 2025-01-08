/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:35 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/08 10:02:01 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(t_f *f, double zx, double zy, double c_re, double c_im)
{
	int		iter;
	double	tmp;

	iter = 0;
	tmp = 0;
	while (zx * zx + zy * zy < 4 && iter < f->max_iter)
	{
		tmp = zx * zx - zy * zy + c_re;
		zy = 2 * zx * zy + c_im;
		zx = tmp;
		iter++;
	}
	return (iter);
}

static void	julia_set(t_f *f)
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
			color_pixel(f, x, y, iterate_julia(f, complex.cx, complex.cy, f->c_re, f->c_im));
			x++;
		}
		y++;
	}
}

void	julia(t_f *f)
{
	if (!f)
		exit(1);
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 950, 700, "Julia");
	init_julia(f);
	num_julia(f, f->max_iter);
	julia_set(f);
	mlx_key_hook(f->win, key_esc, NULL);
	mlx_hook(f->win, 17, 0, close_win, f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_loop(f->mlx);
}

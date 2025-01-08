/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:35 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/08 15:06:03 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_f *f)
{
	f->min_re = -2.0;
	f->max_re = 1.0;
	f->min_im = -1.5;
	f->max_im = 1.5;
	f->max_iter = 50;
	f->img = mlx_new_image(f->mlx, 950, 700);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
}

void	init_julia(t_f *f)
{
	f->c_re = 0.0;
	f->c_im = 0.0;
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->max_iter = 50;
	f->img = mlx_new_image(f->mlx, 950, 700);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
}

void	num_julia(t_f *f, int number)
{
	if (number == 1)
	{
		f->c_re = -0.8;
		f->c_im = 0.156;
		f->form1 = 0.45;
		f->form2 = 0.1428;
	}
	else if (number == 2)
	{
		f->c_re = 0.285;
		f->c_im = 0.01;
		f->form1 = 0.4;
		f->form2 = 0.6;
	}
	else
	{
		f->c_re = 0;
		f->c_im = 0;
	}
}

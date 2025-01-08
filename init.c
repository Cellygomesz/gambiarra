/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:35 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/08 09:23:41 by mgomes-s         ###   ########.fr       */
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
	f->min_re = -2.0;
	f->max_re = 2.0;
	f->min_im = -2.0;
	f->max_im = 2.0;
	f->max_iter = 50;
	f->img = mlx_new_image(f->mlx, 950, 700);
	f->img_addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
}

void num_julia(t_f *f, int number)
{
    if (number == 1)
    {
        f->c_re = -0.8;
        f->c_im = 0.156;
    }
    else if (number == 2)
    {
        f->c_re = 0.285;
        f->c_im = 0.01;
    }
    else
    {
        f->c_re = 0;
        f->c_im = 0;
    }
}

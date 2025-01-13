/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:21:56 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/13 13:30:09 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_f *f)
{
	if (f->type == 1)
	{
		draw_mandelbrot(f);
	}
	else if (f->type == 0)
	{
		julia_set(f);
	}
}

void	zoom(int button, t_f *f)
{
	double	old_size_re;
	double	old_size_im;
	double	new_size;

	if (button == 4)
		f->interpolation = 0.9;
	else if (button == 5)
		f->interpolation = 1.1;
	else
		return ;
	old_size_re = (f->max_re - f->min_re);
	new_size = (f->interpolation * old_size_re);
	f->max_re +=(new_size - old_size_re) / 2.0;
	f->min_re -= (new_size - old_size_re) / 2.0;

	old_size_im = (f->max_im - f->min_im);
	new_size = (f->interpolation * old_size_im);
	f->max_im +=(new_size - old_size_im) / 2.0;
	f->min_im -= (new_size - old_size_im) / 2.0;
	f->zoom_level *= f->interpolation;
    render_fractal(f);
}

int	mouse_hook(int button, int x, int y, t_f *f)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
		zoom(button, f);
	return (0);
}

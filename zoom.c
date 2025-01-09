/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 08:21:56 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/09 08:56:51 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int button, t_f *f)
{
	double	interpolation;
	double	range_re;
	double	range_im;
	double	center_re;
	double	center_im;

	if (button == 4)
		interpolation = 0.9;
	else if (button == 5)
		interpolation = 1.1;
	else
		return ;
	range_re = (f->max_re - f->min_re) * interpolation;
	range_im = (f->max_im - f->min_im) * interpolation;
	center_re = (f->max_re + f->min_re) / 2;
	center_im = (f->max_im + f->min_im) / 2;
	f->min_re = center_re - range_re / 2;
    f->max_re = center_re + range_re / 2;
    f->min_im = center_im - range_im / 2;
    f->max_im = center_im + range_im / 2;
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

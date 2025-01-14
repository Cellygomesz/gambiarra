/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:35 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/14 12:13:18 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*"scales" the pixel position (x, y) to the coordinates of the complex plane.*/

t_complex	map_to_complex_plane(t_f *f, int x, int y)
{
	t_complex	complex;

	complex.cx = f->min_re + (x * (f->max_re - f->min_re) / 950);
	complex.cy = f->min_im + (y * (f->max_im - f->min_im) / 700);
	complex.form1 = f->form1;
	complex.form2 = f->form2;
	return (complex);
}

static int	calculate_mandelbrot(t_f *f, int x, int y)
{
	t_complex	cm;
	double		temp;
	int			i;

	i = 0;
	cm = map_to_complex_plane(f, x, y);
	cm.zx = 0.0;
	cm.zy = 0.0;
	temp = 0.0;
	while ((cm.zx * cm.zx + cm.zy * cm.zy <= 4.0) && (i < f->max_iter))
	{
		temp = cm.zx * cm.zx - cm.zy * cm.zy + cm.cx;
		cm.zy = 2.0 * cm.zx * cm.zy + cm.cy;
		cm.zx = temp;
		i++;
	}
	if (i == f->max_iter)
		return (0x000000);
	return (((0x6b104b * f->zoom_level) / f->max_iter) * i);
}

void	color_pixel(t_f *f, int x, int y, int color)
{
	*(int *)(f->img_addr + (y * f->line_len + x * (f->bpp / 8))) = color;
}

void	draw_mandelbrot(t_f *f)
{
	int	x;
	int	y;
	int	color;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < 700)
	{
		x = 0;
		while (x < 950)
		{
			color_pixel(f, x, y, color);
			color = calculate_mandelbrot(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

void	mandelbrot(t_f *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, 950, 700, "Mandelbrot");
	init_mandelbrot(f);
	draw_mandelbrot(f);
	mlx_key_hook(f->win, key_esc, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0, close_win, f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_loop(f->mlx);
}

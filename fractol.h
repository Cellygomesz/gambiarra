/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:45 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/14 11:50:08 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

typedef struct s_f
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	int			max_iter;
	double		c_re;
	double		c_im;
	double		form1;
	double		form2;
	int			type;
	double		interpolation;
	double		zoom_level;
}	t_f;

typedef struct s_complex
{
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		form1;
	double		form2;
}	t_complex;

/*----- main.c -----*/
int			main(int ac, char **av);

/*----- aux.c -----*/
int			ft_strcmp(const char *s1, const char *s2);
int			mini_atoi(char nptr);
int			key_esc(int num, void *param, t_f *f);
int			close_win(t_f *t);

/*----- mandelbrot.c -----*/
void		mandelbrot(t_f *f);
void		init_mandelbrot(t_f *f);
void		draw_mandelbrot(t_f *f);

/*----- julia.c -----*/
void		julia(t_f *f);
void		num_julia(t_f *f, int number);
void		init_julia(t_f *f);
void		julia_set(t_f *f);

/*----- julia and mandelbrot -----*/
t_complex	map_to_complex_plane(t_f *f, int x, int y);
void		color_pixel(t_f *f, int x, int y, int color);

/*----- zoom.c -----*/
int			mouse_hook(int button, int x, int y, t_f *f);

#endif

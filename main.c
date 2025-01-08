/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 19:09:21 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/08 09:52:02 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	user_error(void)
{
	write(2, "----- ERROR! -----\n", 19);
	write(2, "use: ", 5);
	write(2, "./a.out julia num ", 18);
	write(2, "OR ", 3);
	write(2, "./a.out mandelbrot\n", 19);
}

static int	is_num(char str)
{
	if (str == '1' || str == '2')
		return (0);
	return (1);
}

#include <stdio.h>

int	main(int ac, char **av)
{
    int num;
	t_f	f;

    num = 0;
	(void)ac;
	if (av[0] && !av[1])
		user_error();
	else if (ft_strcmp(av[1], "mandelbrot") == 0 && !av[2])
		mandelbrot(&f);
	else if (ft_strcmp(av[1], "julia") == 0 && av[2] && is_num(av[2][0]) == 0)
	{
		num = mini_atoi(av[2][0]);
        num_julia(&f, num);
		julia(&f);
	}
	else
		user_error();
	return (0);
}

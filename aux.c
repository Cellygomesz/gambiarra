/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2025/01/14 11:21:33 by mgomes-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	mini_atoi(char nptr)
{
	int	temp;

	temp = 0;
	temp = (nptr - '0') + (temp * 10);
	return (temp);
}

/*function that closes the window on esc*/
int	key_esc(int num, void *param, t_f *t)
{
	if (num == 65307)
	{
		free_all(t);
		exit(0);
	}
	return (0);
}

/*function that closes the window in x*/
int	close_win(t_f *f)
{
	free_all(f);
	exit(0);
	return (0);
}

static void	free_all(t_f *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

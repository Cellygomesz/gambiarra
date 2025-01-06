/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-s <mgomes-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:11:23 by mgomes-s          #+#    #+#             */
/*   Updated: 2024/12/17 13:08:36 by mgomes-s         ###   ########.fr       */
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
int	key_esc(int num, void *param)
{
	(void)param;
	if (num == 65307)
		exit(0);
	return (0);
}

/*function that closes the window in x*/
int	close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}   
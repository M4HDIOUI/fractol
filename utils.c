/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:15:01 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:53:33 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	which_julia(t_data *data)
{
	if (data->www == 1)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_julia(data);
	}
	else if (data->www == 11)
	{
		data->r = -0.70176;
		data->i = -0.3842;
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_julia(data);
	}
	else if (data->www == 12)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		data->r = 0.285;
		data->i = 0.01;
		draw_julia(data);
	}
}

void	which_fractal(t_data *data)
{
	if (data->www == 2)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_mandelbrot(data);
	}
	else if (data->www == 3)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		draw_burningship(data);
	}
	else
		which_julia(data);
}

void	keys(int key, t_data *data)
{
	if (key == 124)
	{
		data->xmn = data->xmn - 0.2;
		data->xmx = data->xmx - 0.2;
	}
	if (key == 123)
	{
		data->xmn = data->xmn + 0.2;
		data->xmx = data->xmx + 0.2;
	}
	if (key == 126)
	{
		data->ymx = data->ymx + 0.2;
		data->ymn = data->ymn + 0.2;
	}
	if (key == 125)
	{
		data->ymx = data->ymx - 1;
		data->ymn = data->ymn - 1;
	}
}

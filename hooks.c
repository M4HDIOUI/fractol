/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:42:32 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:53:23 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	keys(key, data);
	which_fractal(data);
	return (0);
}

int	mouse(int key, int x, int y, t_data *data)
{
	if (key == 4)
		data->interpolation = 1.2;
	else if (key == 5)
		data->interpolation = 0.8;
	else
		return (0);
	apply_zoom(data, x, y);
	which_fractal(data);
	return (0);
}

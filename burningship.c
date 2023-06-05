/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:11:13 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:53:18 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_burningship(t_data *data)
{
	double	x;
	double	y;
	double	x0;
	double	y0;
	double	xtemp;

	x = 0;
	y = 0;
	data->iteration = 0;
	x0 = data->xmn + data->x * (data->xmx - data->xmn) / 1000;
	y0 = data->ymn + data->y * (data->ymx - data->ymn) / 1000;
	while (x * x + y * y < 4 && data->iteration < 100)
	{
		xtemp = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = xtemp;
		data->iteration++;
	}
	return (data->iteration);
}

void	draw_burningship(t_data *data)
{
	int	i;

	data->y = 0;
	while (data->y < 1000)
	{
		data->x = 0;
		while (data->x < 1000)
		{
			i = iter_burningship(data);
			if (i == 100)
				my_mlx_pixel_put(data, data->x, data->y, 0x000000);
			else
				my_mlx_pixel_put(data, data->x, data->y, 0xB1AE39 * i);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->mlx_img, 0, 0);
}

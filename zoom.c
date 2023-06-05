/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:17:48 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:53:36 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_data *data, double x, double y)
{
	x = (double)x / (1000 / (data->xmx - data->xmn)) + data->xmn;
	y = (double)y / (1000 / (data->ymx - data->ymn)) + data->ymn;
	data->xmn = interpolate(x, data->xmn, data->interpolation);
	data->ymn = interpolate(y, data->ymn, data->interpolation);
	data->xmx = interpolate(x, data->xmx, data->interpolation);
	data->ymx = interpolate(y, data->ymx, data->interpolation);
}

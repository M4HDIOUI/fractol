/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 02:47:49 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:53:21 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

void	which_julia1(t_data *data, char **av)
{
	if (ft_strcmp("julia", av[1]) == 0)
	{
		data->www = 1;
		draw_julia(data);
	}
	else if (ft_strcmp("julia1", av[1]) == 0)
	{
		data->www = 11;
		data->r = -0.70176;
		data->i = -0.3842;
		draw_julia(data);
	}
	else if (ft_strcmp("julia2", av[1]) == 0)
	{
		data->www = 12;
		data->r = 0.285;
		data->i = 0.01;
		draw_julia(data);
	}
}

void	check_av(char **av, t_data *data)
{
	if (ft_strcmp("mandelbrot", av[1]) == 0)
	{
		data->www = 2;
		draw_mandelbrot(data);
	}
	else if (ft_strcmp("burningship", av[1]) == 0)
	{
		data->www = 3;
		draw_burningship(data);
	}
	else if (ft_strcmp("julia", av[1]) == 0
		|| ft_strcmp("julia1", av[1]) == 0 || ft_strcmp("julia2", av[1]) == 0)
		which_julia1(data, av);
	else
	{
		write(2, "Invalid parameter!\n", 20);
		exit(1);
	}
}

void	initial(t_data *data)
{
	data->r = 0;
	data->i = 0.8;
	data->xmn = -2;
	data->xmx = 2;
	data->ymx = 2;
	data->ymn = -2;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
	{	
		write(2, "Error!", 6);
		exit (1);
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	initial(data);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1000, 1000, "fractal");
	data->mlx_img = mlx_new_image(data->mlx, 1000, 1000);
	data->addr = mlx_get_data_addr(data->mlx_img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	check_av(av, data);
	mlx_hook(data->mlx_win, 17, 0, close_win, data);
	mlx_key_hook(data->mlx_win, key, data);
	mlx_mouse_hook(data->mlx_win, mouse, data);
	mlx_loop(data->mlx);
	return (0);
}

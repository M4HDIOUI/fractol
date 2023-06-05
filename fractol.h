/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omahdiou <omahdiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:57:13 by omahdiou          #+#    #+#             */
/*   Updated: 2023/06/04 22:57:47 by omahdiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     FRACTOL_H
# define    FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		iteration;
	char	**avtmp;
	double	zoom;
	double	xmn;
	double	ymn;
	double	xmx;
	double	ymx;
	double	r;
	double	i;
	int		www;
	double	interpolation;
	int		x;
	int		y;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		iter_burningship(t_data *data);
void	draw_burningship(t_data *data);
int		close_win(t_data *data);
int		key(int key, t_data *data);
void	which_julia1(t_data *data, char **av);
void	check_av(char **av, t_data *data);
int		mouse(int key, int x, int y, t_data *data);
void	initial(t_data *data);
int		iter_julia(t_data *data);
void	draw_julia(t_data *data);
int		iter_mandelbrot(t_data *data);
void	draw_mandelbrot(t_data *data);
int		ft_strcmp(char *str1, char *str2);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	which_julia(t_data *data);
void	which_fractal(t_data *data);
void	keys(int key, t_data *data);
double	interpolate(double start, double end, double interpolation);
void	apply_zoom(t_data *data, double x, double y);

#endif

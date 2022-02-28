/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:53:53 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 23:04:09 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

# define TRUE		1
# define FALSE		0

# define KEY_UP		0x7e
# define KEY_DOWN	0x7d
# define KEY_LEFT	0x7b
# define KEY_RIGHT	0x7c

# define PLUS		0x18
# define MINUS		0x1B

# define KEY_ESC	0x35
# define RED_DOT	0x11
# define MOUSE_MOVE	0x06
# define ZOOM_IN	0x05
# define ZOOM_OUT	0x04

# define WIN_WIDTH	800
# define WIN_HEIGHT	600

# define RGB_OFFSET 0.3
# define COLOR_MAX	255
# define ITER_MAX	100

typedef unsigned int	t_uint;

typedef struct s_img
{
	void	*imgptr;
	char	*data;
	int		lsize;
	int		bpp;
	int		endian;
	double	zoomxy[2];
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	double	cx;
	double	cy;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		fractal;
}				t_mlx;

typedef struct s_cmplx
{
	double	real;
	double	imagin;
}				t_cmplx;

int		init_win(t_mlx *mlx);
int		close_mlx(t_mlx *mlx);
void	error_msg(char *msg);

void	mandelbrot(void);
void	init_m(t_mlx *mlx);

void	julia(void);
void	init_j(t_mlx *mlx);

int		mouse_handler(int code, int x, int y, t_mlx *mlx);
int		key_handler(int code, t_mlx *mlx);
void	zoom(int greater, t_img *img);
void	click(int code, int x, int y, t_mlx *mlx);
int		mmove(int x, int y, t_mlx *mlx);

void	init_px(int x, int y, t_uint color, t_img *img);
t_uint	cal_colour(double idx);

#endif

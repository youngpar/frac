/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:18:01 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 23:05:45 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static t_uint	valid_set(double x, double y, t_img *img)
{
	t_cmplx	z;
	t_cmplx	c;
	double	tmp;
	t_uint	idx;

	c.real = x / (WIN_WIDTH / (img->xmax - img->xmin)) + img->xmin;
	c.imagin = y / (WIN_HEIGHT / (img->ymax - img->ymin)) + img->ymin;
	idx = -1;
	ft_memset(&z, 0, sizeof(z));
	while ((z.real * z.real + z.imagin * z.imagin < 4) && (++idx < ITER_MAX))
	{
		tmp = z.real;
		z.real = z.real * z.real - z.imagin * z.imagin + c.real;
		z.imagin = 2 * tmp * z.imagin + c.imagin;
	}
	return (idx);
}

void	init_m(t_mlx *mlx)
{
	int		idx;
	int		xy[2];
	int		color;

	xy[0] = -1;
	while (++xy[0] < WIN_WIDTH)
	{
		xy[1] = -1;
		while (++xy[1] < WIN_HEIGHT)
		{
			idx = valid_set(xy[0], xy[1], &mlx->img);
			if (idx < ITER_MAX)
			{
				color = cal_colour(idx);
				init_px(xy[0], xy[1], color, &mlx->img);
			}
			else
				init_px(xy[0], xy[1], 0x00000000, &mlx->img);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.imgptr, 0, 0);
}

void	mandelbrot(void)
{
	t_mlx	mlx;

	if (!init_win(&mlx))
	{
		perror("Failed to Connect with X-Window\n");
		close_mlx(&mlx);
	}
	mlx.fractal = 0;
	mlx.img.xmin = -2;
	mlx.img.xmax = 2;
	mlx.img.ymin = -1.5;
	mlx.img.ymax = 1.5;
	init_m(&mlx);
	mlx_key_hook(mlx.win_ptr, (*key_handler), &mlx);
	mlx_mouse_hook(mlx.win_ptr, (*mouse_handler), &mlx);
	mlx_hook(mlx.win_ptr, MOUSE_MOVE, 0, *mmove, &mlx);
	mlx_hook(mlx.win_ptr, RED_DOT, 0, close_mlx, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

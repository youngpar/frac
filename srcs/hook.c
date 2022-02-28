/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:52:40 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 22:32:49 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	move(int code, t_img *img)
{
	double	xoffset;
	double	yoffset;

	xoffset = (img->xmax - img->xmin) / 10;
	yoffset = (img->ymax - img->ymin) / 10;
	if (code == KEY_UP)
	{
		img->ymin -= yoffset;
		img->ymax -= yoffset;
	}
	else if (code == KEY_DOWN)
	{
		img->ymin += yoffset;
		img->ymax += yoffset;
	}
	else if (code == KEY_LEFT)
	{
		img->xmin -= xoffset;
		img->xmax -= xoffset;
	}
	else if (code == KEY_RIGHT)
	{
		img->xmin += xoffset;
		img->xmax += xoffset;
	}
}

int	key_handler(int code, t_mlx *mlx)
{
	if (code == KEY_ESC)
		close_mlx(mlx);
	if (code == PLUS)
		zoom(TRUE, &mlx->img);
	else if (code == MINUS)
		zoom(FALSE, &mlx->img);
	if (code == KEY_UP || code == KEY_DOWN
		|| code == KEY_LEFT || code == KEY_RIGHT)
		move(code, &mlx->img);
	if (!mlx->fractal)
		init_m(mlx);
	else
		init_j(mlx);
	return (0);
}

void	click(int code, int x, int y, t_mlx *mlx)
{
	double	ox;
	double	oy;

	ox = mlx->img.cx;
	oy = mlx->img.cy;
	if (code == 1)
	{
		mlx->img.xmax += ox;
		mlx->img.ymax += oy;
		mlx->img.xmin += ox;
		mlx->img.ymin += oy;
		zoom(TRUE, &mlx->img);
		return ;
	}
	mlx->img.xmax -= ox;
	mlx->img.ymax -= oy;
	mlx->img.xmin -= ox;
	mlx->img.ymin -= oy;
	zoom(FALSE, &mlx->img);
}

int	mouse_handler(int code, int x, int y, t_mlx *mlx)
{
	if (code == 1 || code == 2)
		click(code, x, y, mlx);
	if (code == ZOOM_IN)
		zoom(TRUE, &(mlx->img));
	else if (code == ZOOM_OUT)
		zoom(FALSE, &(mlx->img));
	if (!mlx->fractal)
		init_m(mlx);
	else
		init_j(mlx);
	return (0);
}

int	mmove(int x, int y, t_mlx *mlx)
{
	mlx->img.cx = (x - WIN_WIDTH / 2)
		* (mlx->img.xmax - mlx->img.xmin) / WIN_WIDTH;
	mlx->img.cy = (y - WIN_HEIGHT / 2)
		* (mlx->img.ymax - mlx->img.ymin) / WIN_HEIGHT;
	if (mlx->fractal)
		init_j(mlx);
	return (0);
}

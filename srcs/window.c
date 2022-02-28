/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:18:06 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 22:22:42 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_win(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (0);
	mlx->win_ptr = mlx_new_window(
			mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	if (!mlx->win_ptr)
		return (0);
	mlx->img.imgptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img.imgptr)
		return (0);
	mlx->img.data = mlx_get_data_addr(
			mlx->img.imgptr, &mlx->img.bpp, &mlx->img.lsize, &mlx->img.endian);
	if (!mlx->img.data)
		return (0);
	return (1);
}

int	close_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit(0);
	}
	return (0);
}

void	error_msg(char *msg)
{
	perror(msg);
	exit(0);
}

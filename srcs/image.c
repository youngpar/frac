/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:39 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 23:04:57 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_uint	cal_colour(double idx)
{
	double	r;
	double	g;
	double	b;
	t_uint	color;

	r = sin(RGB_OFFSET * idx);
	g = tan(RGB_OFFSET * idx) * 127 + 128;
	b = cos(RGB_OFFSET * idx) * 127 + 128;
	color = ((t_uint)(COLOR_MAX * r) << 16)
		| ((t_uint)(COLOR_MAX * g) << 8) | (t_uint)(COLOR_MAX * b);
	return (color);
}

void	init_px(int x, int y, t_uint color, t_img *img)
{
	void	*pixel;

	pixel = img->data + (x * img->bpp / 8) + (y * img->lsize);
	*(unsigned int *)pixel = color;
}

void	zoom(int greater, t_img *img)
{
	img->zoomxy[0] = (img->xmax - img->xmin) / 10;
	img->zoomxy[1] = (img->ymax - img->ymin) / 10;
	if (greater)
	{
		img->xmin += img->zoomxy[0];
		img->xmax -= img->zoomxy[0];
		img->ymin += img->zoomxy[1];
		img->ymax -= img->zoomxy[1];
	}
	else
	{
		img->xmin -= img->zoomxy[0];
		img->xmax += img->zoomxy[0];
		img->ymin -= img->zoomxy[1];
		img->ymax += img->zoomxy[1];
	}
}

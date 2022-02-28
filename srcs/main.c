/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngpar <youngseo321@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:32:25 by youngpar          #+#    #+#             */
/*   Updated: 2022/02/28 22:39:15 by youngpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error_msg("Usage: ./fractol [mandelbrot] OR [julia]\n");
	else
	{
		if (!ft_strncmp("mandelbrot", argv[1], ft_strlen(argv[1])))
			mandelbrot();
		else if (!ft_strncmp("julia", argv[1], ft_strlen(argv[1])))
			julia();
		else
			error_msg("Input parameter is only [mandelbrot] OR [julia]\n");
	}
	return (0);
}

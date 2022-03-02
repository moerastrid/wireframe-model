/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 14:32:13 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 21:49:22 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdflib.h"

void	ft_stop(t_mlx *my_mlx)
{
	mlx_terminate(my_mlx);
}

void	ft_pixelputwrap(t_img *img, int x, int y, unsigned int color)
{
	if (x < img->width && y < img->height)
		mlx_putpixel(img, x, y, color);
}

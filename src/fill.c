/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 18:18:36 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 21:08:22 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdflib.h"

void	ft_fill(t_img *img, t_mlx *mlx)
{
	int				i;
	int				j;
	unsigned int	color;
	int				green;

	green = 90;
	color = ft_make_color(90, green, 220);
	j = 0;
	while (j < mlx->height)
	{
		i = 0;
		if (j % 3 && green <= 190)
			green = 90 + (j / 6);
		else
			green = 190;
		while (i < mlx->width)
		{
			color = ft_make_color(90, green, 220);
			ft_pixelputwrap(img, i, j, color);
			i++;
		}
		j++;
	}
}

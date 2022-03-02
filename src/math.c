/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   math.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 17:09:14 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 21:48:50 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

void	ft_isometric(int *x, int *y, int z, int steepness)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -(z * steepness * 0.3) + (previous_x + previous_y) * sin(0.523599);
}

void	ft_math_hor(int i, int j, t_map *mapdata, int **map)
{
	mapdata->ya = j * mapdata->zoom;
	mapdata->yb = j * mapdata->zoom;
	mapdata->xa = i * mapdata->zoom;
	mapdata->xb = (i + 1) * mapdata->zoom;
	ft_isometric(&mapdata->xa, &mapdata->ya, map[j][i], mapdata->steepness);
	mapdata->xa += mapdata->offsetx;
	mapdata->ya += mapdata->offsety;
	ft_isometric(&mapdata->xb, &mapdata->yb, map[j][i + 1], mapdata->steepness);
	mapdata->xb += mapdata->offsetx;
	mapdata->yb += mapdata->offsety;
}

void	ft_math_ver(int i, int j, t_map *mapdata, int **map)
{
	mapdata->ya = j * mapdata->zoom;
	mapdata->yb = (j + 1) * mapdata->zoom;
	mapdata->xa = i * mapdata->zoom;
	mapdata->xb = i * mapdata->zoom;
	ft_isometric(&mapdata->xa, &mapdata->ya, map[j][i], mapdata->steepness);
	mapdata->xa += mapdata->offsetx;
	mapdata->ya += mapdata->offsety;
	ft_isometric(&mapdata->xb, &mapdata->yb, map[j + 1][i], mapdata->steepness);
	mapdata->xb += mapdata->offsetx;
	mapdata->yb += mapdata->offsety;
}

void	ft_draw(int **map, t_map *mapdata, t_img *img, t_mlx *mlx)
{
	int	i;
	int	j;

	ft_fill(img, mlx);
	j = 0;
	while (j < mapdata->ver)
	{
		i = 0;
		while (i < mapdata->hor)
		{
			if ((i + 1) < mapdata->hor)
			{
				ft_math_hor(i, j, mapdata, map);
				ft_line(img, mapdata);
			}
			if ((j + 1) < mapdata->ver)
			{
				ft_math_ver(i, j, mapdata, map);
				ft_line(img, mapdata);
			}
			i++;
		}
		j++;
	}
	return ;
}

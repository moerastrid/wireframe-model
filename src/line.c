/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 18:18:27 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/14 17:49:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

void	updownleftright(t_img *img, t_map *mapdata, float mn[2])
{
	while (mapdata->ya <= mapdata->yb && mapdata->xa <= mapdata->xb)
	{
		ft_pixelputwrap(img, mapdata->xa, mapdata->ya, 0xEEEEEEFF);
		if (mapdata->ya <= (mn[0] * mapdata->xa) + mn[1]
			&& (mapdata->ya + 1) >= (mn[0] * mapdata->xa) + mn[1])
			mapdata->xa++;
		else
			mapdata->ya++;
	}
	return ;
}

void	downupleftright(t_img *img, t_map *mapdata, float mn[2])
{
	while (mapdata->ya >= mapdata->yb && mapdata->xa <= mapdata->xb)
	{
		ft_pixelputwrap(img, mapdata->xa, mapdata->ya, 0x99EEEEFF);
		if (mapdata->ya <= (mn[0] * mapdata->xa) + mn[1]
			&& (mapdata->ya + 1) > (mn[0] * mapdata->xa + mn[1]))
			mapdata->xa++;
		else
			mapdata->ya--;
	}
}

void	updownrightleft(t_img *img, t_map *mapdata, float mn[2])
{
	while (mapdata->ya <= mapdata->yb && mapdata->xa >= mapdata->xb)
	{
		ft_pixelputwrap(img, mapdata->xa, mapdata->ya, 0xEE99EEFF);
		if (mapdata->ya >= (mn[0] * mapdata->xa) + mn[1]
			&& (mapdata->ya - 1) <= (mn[0] * mapdata->xa) + mn[1])
			mapdata->xa--;
		else
			mapdata->ya++;
	}
}

void	downuprightleft(t_img *img, t_map *mapdata, float mn[2])
{
	while (mapdata->ya >= mapdata->yb && mapdata->xa >= mapdata->xb)
	{
		ft_pixelputwrap(img, mapdata->xa, mapdata->ya, 0xEEEE99FF);
		if (mapdata->ya >= (mn[0] * mapdata->xa) + mn[1]
			&& (mapdata->ya - 1) <= (mn[0] * mapdata->xa + mn[1]))
			mapdata->xa--;
		else
			mapdata->ya--;
	}
}

void	ft_line(t_img *img, t_map *mapdata)
{
	float		xd;
	float		yd;
	float		mn[2];

	xd = mapdata->xb - mapdata->xa;
	yd = mapdata->yb - mapdata->ya;
	mn[0] = yd / xd;
	mn[1] = mapdata->ya - (mapdata->xa * mn[0]);
	if (mapdata->ya <= mapdata->yb && mapdata->xa <= mapdata->xb)
		updownleftright(img, mapdata, mn);
	else if (mapdata->ya >= mapdata->yb && mapdata->xa <= mapdata->xb)
		downupleftright(img, mapdata, mn);
	else if (mapdata->ya <= mapdata->yb && mapdata->xa >= mapdata->xb)
		updownrightleft(img, mapdata, mn);
	else if (mapdata->ya >= mapdata->yb && mapdata->xa >= mapdata->xb)
		downuprightleft(img, mapdata, mn);
	return ;
}

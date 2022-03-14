/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 16:58:15 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/14 17:54:27 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdflib.h"

int	ft_check_args(int num, char *filename)
{
	if (num != 2)
	{
		write(1, "What map do you want?\n", 22);
		return (0);
	}
	if (ft_strncmp(filename, "test_maps/\0", 11) == 0
		|| ft_strncmp(filename, "test_maps\0", 10) == 0)
	{
		write(1, "issa folder", 11);
		return (0);
	}
	return (1);
}

void	ft_putmapdata(t_mlx *my_mlx, t_img *my_img, t_map *mapdata)
{
	mapdata->mlx = my_mlx;
	mapdata->img = my_img;
	mapdata->offsetx = my_mlx->width / 2;
	mapdata->offsety = my_mlx->height / 4;
	mapdata->zoom = 15;
	mapdata->steepness = 3;
	mapdata->angle = 0.523599;
}

void	ft_makevar(t_map *mapdata, char *path, t_var *my_var)
{
	my_var->my_mlx = mapdata->mlx;
	my_var->my_img = mapdata->img;
	my_var->mapdata = mapdata;
	my_var->path = path;
}

int	main(int argc, char **argv)
{
	t_var	my_var;
	t_mlx	*my_mlx;
	t_img	*my_img;
	t_map	mapdata;

	if (ft_check_args(argc, argv[1]) == 0)
		return (0);
	my_mlx = mlx_init(WIDTH, HEIGHT, "frame it", false);
	my_img = mlx_new_image(my_mlx, my_mlx->width, my_mlx->height);
	ft_putmapdata(my_mlx, my_img, &mapdata);
	if (ft_map(argv[1], &mapdata, my_img, my_mlx) == -1)
	{
		ft_stop(my_mlx);
		return (0);
	}
	mlx_image_to_window(my_mlx, my_img, 0, 0);
	ft_makevar(&mapdata, argv[1], &my_var);
	mlx_key_hook(my_mlx, ft_keypress, &my_var);
	mlx_loop(my_mlx);
	ft_stop(my_mlx);
	return (0);
}

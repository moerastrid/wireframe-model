/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 16:58:15 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 21:32:48 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdflib.h"
#include "MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_var	my_var;
	t_mlx	*my_mlx;
	t_img	*my_img;
	t_map	mapdata;

	my_mlx = mlx_init(WIDTH, HEIGHT, "frame it", false);
	my_img = mlx_new_image(my_mlx, my_mlx->width, my_mlx->height);
	mapdata.offsetx = my_mlx->width / 2;
	mapdata.offsety = my_mlx->height / 4;
	mapdata.zoom = 15;
	mapdata.steepness = 3;
	ft_map(argv[1], mapdata, my_img, my_mlx);
	mlx_image_to_window(my_mlx, my_img, 0, 0);
	my_var.my_mlx = my_mlx;
	my_var.my_img = my_img;
	my_var.mapdata = mapdata;
	my_var.path = argv[1];
	mlx_key_hook(my_mlx, ft_keypress, &my_var);
	mlx_loop(my_mlx);
	ft_stop(my_mlx);
	return (0);
}

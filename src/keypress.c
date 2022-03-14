/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 18:18:32 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/14 18:19:28 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

void	ft_movey(t_mlx_key_cbdata keydata, t_var *var)
{
	if (keydata.key == MLX_KEY_UP
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->offsety -= 10;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_DOWN
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->offsety += 10;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
}

void	ft_movex(t_mlx_key_cbdata keydata, t_var *var)
{
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->offsetx -= 10;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->offsetx += 10;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
}

void	ft_zoomangle(t_mlx_key_cbdata keydata, t_var *var)
{
	if (keydata.key == MLX_KEY_M
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
		&& var->mapdata->zoom > 1)
	{
		var->mapdata->zoom -= 2;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_P
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->zoom += 2;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_X
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
		&& var->mapdata->angle > 0.1)
	{
		var->mapdata->angle -= 0.1;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
}

void	ft_steepangle(t_mlx_key_cbdata keydata, t_var *var)
{
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
	{
		var->mapdata->steepness += 1;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_F
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
		&& var->mapdata->steepness > 0)
	{
		var->mapdata->steepness -= 1;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
	if (keydata.key == MLX_KEY_Z
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS)
		&& var->mapdata->angle < ((M_PI / 4) - 0.1))
	{
		var->mapdata->angle += 0.1;
		ft_map(var->path, var->mapdata, var->my_img, var->my_mlx);
	}
}

void	ft_keypress(t_mlx_key_cbdata keydata, void *invar)
{
	t_var	*var;

	var = (t_var *)invar;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(var->my_mlx);
	ft_movey(keydata, var);
	ft_movex(keydata, var);
	ft_zoomangle(keydata, var);
	ft_steepangle(keydata, var);
}

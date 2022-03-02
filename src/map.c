/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 19:17:23 by ageels        #+#    #+#                 */
/*   Updated: 2022/02/25 18:54:52 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

void	ft_toomanylines(t_int *te, t_map *mapdata)
{
	while (te->j < mapdata->ver)
	{
		((int **)te->start_ptr)[te->j]
			= &((int *)te->int_ptr)[te->j * mapdata->hor];
		te->lines = get_next_line(te->fd);
		te->dots = ft_split(te->lines, ' ');
		te->i = 0;
		while (te->i < mapdata->hor)
		{
			((int *)te->int_ptr)[te->j * mapdata->hor + te->i]
				= ft_atoi(te->dots[te->i]);
			te->i++;
		}
		free(te->dots);
		free(te->lines);
		te->j++;
	}
	return ;
}

int	**ft_make_map(t_map mapdata)
{
	t_int	te;

	te.fd = open(mapdata.path, O_RDONLY);
	te.start_ptr = calloc(2 + mapdata.ver * (2 + mapdata.hor), 4);
	if (te.start_ptr == NULL)
		return (te.start_ptr);
	te.int_ptr = te.start_ptr + 8 * (mapdata.ver + 1);
	te.lines = NULL;
	te.j = 0;
	ft_toomanylines(&te, &mapdata);
	close(te.fd);
	return ((int **)te.start_ptr);
}

t_map	ft_scan_map(t_map mapdata)
{
	int		fd;
	char	*lines;
	char	**dots;

	mapdata.ver = 0;
	dots = NULL;
	fd = open(mapdata.path, O_RDONLY);
	lines = "hoi";
	while (lines != NULL)
	{
		lines = get_next_line(fd);
		if (lines != NULL)
		{
			dots = ft_split(lines, ' ');
			mapdata.hor = 0;
			while (dots[mapdata.hor] != NULL
				&& ft_strncmp(dots[mapdata.hor], "\n", 1) != 0)
				mapdata.hor++;
			mapdata.ver++;
			free(dots);
		}
		free(lines);
	}
	close(fd);
	return (mapdata);
}

void	ft_map(char *path, t_map mapdata, t_img *my_img, t_mlx *my_mlx)
{
	int		**my_map;

	mapdata.path = path;
	mapdata = ft_scan_map(mapdata);
	my_map = ft_make_map(mapdata);
	ft_draw(my_map, &mapdata, my_img, my_mlx);
	free(my_map);
}

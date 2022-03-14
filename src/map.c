/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/14 19:17:23 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/14 17:44:59 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

void	ft_toomanylines(t_int *te, t_map *md)
{
	while (te->j < md->ver)
	{
		((int **)te->start_ptr)[te->j]
			= &((int *)te->int_ptr)[te->j * md->hor];
		te->lines = get_next_line(te->fd);
		te->d = ft_split(te->lines, ' ');
		te->i = 0;
		while (te->i < md->hor)
		{
			((int *)te->int_ptr)[te->j * md->hor + te->i]
				= ft_atoi(te->d[te->i]);
			te->i++;
		}
		free(te->d);
		free(te->lines);
		te->j++;
	}
	return ;
}

int	**ft_make_map(t_map *md)
{
	t_int	te;

	te.fd = open(md->path, O_RDONLY);
	te.start_ptr = calloc(2 + md->ver * (2 + md->hor), 4);
	if (te.start_ptr == NULL)
		return (te.start_ptr);
	te.int_ptr = te.start_ptr + 8 * (md->ver + 1);
	te.lines = NULL;
	te.j = 0;
	ft_toomanylines(&te, md);
	close(te.fd);
	return ((int **)te.start_ptr);
}

int	ft_scan_map(t_map *md)
{
	int		fd;
	char	*lines;
	char	**d;

	md->ver = 0;
	d = NULL;
	fd = open(md->path, O_RDONLY);
	if (fd == -1)
		return (write(1, "wrong fd\n", 9), -1);
	lines = "hoi";
	while (lines != NULL)
	{
		lines = get_next_line(fd);
		if (lines != NULL)
		{
			d = ft_split(lines, ' ');
			md->hor = 0;
			while (d[md->hor] != NULL && ft_strncmp(d[md->hor], "\n", 1) != 0)
				md->hor++;
			md->ver++;
			free(d);
		}
		free(lines);
	}
	return (close(fd), 0);
}

int	ft_map(char *path, t_map *md, t_img *my_img, t_mlx *my_mlx)
{
	int		**my_map;

	md->path = path;
	if (ft_scan_map(md) == -1)
	{
		return (-1);
	}
	my_map = ft_make_map(md);
	ft_draw(my_map, md, my_img, my_mlx);
	free(my_map);
	return (0);
}

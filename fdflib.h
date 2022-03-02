/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdflib.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 22:03:13 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 22:03:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFLIB_H
# define FDFLIB_H
# include "MLX42/MLX42.h"
# include <stdlib.h>
# include <math.h>
# include "get_next_line_copy/get_next_line.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/uio.h>

# define WIDTH 2000
# define HEIGHT 900

typedef t_mlx_image	t_img;

typedef struct s_int
{
	int		i;
	int		j;
	int		fd;
	char	*lines;
	char	**dots;
	void	*int_ptr;
	void	*start_ptr;
}		t_int;

typedef struct s_map
{
	char	*path;
	int		hor;
	int		ver;
	int		xa;
	int		xb;
	int		ya;
	int		yb;
	int		offsetx;
	int		offsety;
	int		zoom;
	int		steepness;
}		t_map;

typedef struct s_var
{
	t_mlx	*my_mlx;
	t_img	*my_img;
	t_map	mapdata;
	char	*path;
}		t_var;

void			ft_fill(t_img *img, t_mlx *mlx);
unsigned int	ft_make_color(int r, int g, int b);
void			ft_keypress(t_mlx_key_cbdata keydata, void *invar);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			ft_map(char *path, t_map mdata, t_img *my_img, t_mlx *my_mlx);
t_map			ft_scan_map(t_map my_map);
int				**ft_make_map(t_map map);
void			ft_toomanylines(t_int *te, t_map *map);
void			ft_isometric(int *x, int *y, int z, int steepness);
void			ft_draw(int **map, t_map *mapdata, t_img *img, t_mlx *mlx);
void			ft_line(t_img *img, t_map *mapdata);
void			ft_stop(t_mlx *my_mlx);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_pixelputwrap(t_img *img, int x, int y, unsigned int color);

#endif
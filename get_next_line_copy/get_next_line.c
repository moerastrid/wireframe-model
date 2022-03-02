/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 22:03:35 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 22:03:36 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*currentline;
	char		*answer;
	char		*justread;
	static char	*leftovers = NULL;

	currentline = NULL;
	if (leftovers)
	{
		currentline = ft_strdup(leftovers);
		free(leftovers);
	}
	leftovers = NULL;
	if (ft_strchr(currentline, '\n') != '\0')
	{
		currentline = ft_wecanreturn(&currentline, &leftovers);
		return (currentline);
	}
	justread = NULL;
	justread = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (justread == 0)
		return (NULL);
	answer = NULL;
	answer = ft_read(fd, &currentline, &leftovers, &justread);
	free(justread);
	return (answer);
}

char	*ft_read(int fd, char **currentline, char **leftovers, char **justread)
{
	int		readreturn;

	readreturn = 1;
	while (readreturn > 0)
	{
		readreturn = read(fd, *justread, BUFFER_SIZE);
		if (readreturn == -1)
			return (NULL);
		*currentline = ft_strljoin(*currentline, *justread, readreturn);
		if (ft_strchr(*currentline, '\n') != '\0')
		{
			*currentline = ft_wecanreturn(currentline, leftovers);
			return (*currentline);
		}
	}
	if (*currentline[0] != '\0')
		return (*currentline);
	free(*currentline);
	return (NULL);
}

char	*ft_wecanreturn(char **currentline, char **leftovers)
{
	int	currentlinelength;
	int	leftoverlength;

	leftoverlength = ft_strlen(ft_strchr(*currentline, '\n'));
	if ((ft_strchr(*currentline, '\n') + 1) != 0)
		*leftovers = ft_strdup(ft_strchr(*currentline, '\n') + 1);
	currentlinelength = ft_strlen(*currentline) - leftoverlength;
	*currentline = ft_substr(*currentline, 0, currentlinelength + 1);
	return (*currentline);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*point;

	point = malloc(count * size);
	if (point == 0)
		return (0);
	ft_bzero(point, size * count);
	return (point);
}

void	ft_bzero(void *s, size_t n)
{
	char	*stemp;
	size_t	a;

	stemp = (char *)s;
	a = 0;
	while (a != n)
	{
		stemp[a] = '\0';
		a++;
	}
}

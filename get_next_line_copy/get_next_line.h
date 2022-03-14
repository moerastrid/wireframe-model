/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 22:03:39 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/14 17:46:40 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# define BUFFER_SIZE 4

char	*get_next_line(int fd);
char	*ft_strdup(const char *original);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *original, unsigned int start, size_t len);
char	*ft_strljoin(char *s1, char const *s2, int retread);
char	*ft_wecanreturn(char **currentline, char **leftovers);
size_t	ft_strlen(const char *string);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_read(int fd, char **currentline, char **leftovers, char **justread);

#endif 
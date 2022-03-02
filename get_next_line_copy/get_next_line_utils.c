/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 22:03:31 by ageels        #+#    #+#                 */
/*   Updated: 2022/03/02 22:03:32 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *original)
{
	char	*duplicate;
	int		a;

	a = 0;
	duplicate = (char *)calloc((ft_strlen(original) + 1), sizeof(char));
	if (duplicate == 0)
		return (0);
	while (original[a] != 0)
	{
		duplicate[a] = original[a];
		a++;
	}
	duplicate[a] = original[a];
	return (duplicate);
}

char	*ft_strchr(const char *s, int c)
{
	int		a;

	if (s == 0)
		return (NULL);
	a = 0;
	while (s[a] != (char)c && s[a] != '\0')
		a++;
	if (s[a] == '\0' && (char)c != '\0')
		return (NULL);
	return ((char *)s + a);
}

char	*ft_substr(char *original, unsigned int start, size_t len)
{
	size_t	a;
	char	*answer;

	if (len > ft_strlen(original))
		len = ft_strlen(original);
	a = 0;
	answer = (char *)malloc(sizeof(char) * (len + 1));
	if (answer == 0)
		return (0);
	if (start < ft_strlen(original))
	{
		while (a < (len))
		{
			answer[a] = original[start];
			a++;
			start++;
		}
	}
	answer[a] = '\0';
	free(original);
	return (answer);
}

char	*ft_strljoin(char *s1, char const *s2, int retread)
{
	int		a;
	int		b;
	char	*ns;

	ns = NULL;
	if (s1 == NULL)
		return (ft_strdup(s2));
	ns = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (ns == 0)
		return (0);
	a = 0;
	while (s1[a] != '\0')
	{
		ns[a] = s1[a];
		a++;
	}
	b = 0;
	while (s2[b] != '\0' && retread > 0)
	{
		ns[a++] = s2[b++];
		retread--;
	}
	free(s1);
	return (ns);
}

size_t	ft_strlen(const char *string)
{
	int	a;

	a = 0;
	while (string[a] != 0)
		a++;
	return (a);
}

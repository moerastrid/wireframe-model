/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftfunctions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 17:51:10 by ageels        #+#    #+#                 */
/*   Updated: 2022/02/25 15:23:29 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*newstring;

	a = 0;
	b = 0;
	c = ft_strlen(s1) + ft_strlen(s2) + 1;
	newstring = (char *)malloc(sizeof(char) * c);
	if (newstring == 0)
		return (0);
	while (s1[a] != 0)
	{
		newstring[a] = s1[a];
		a++;
	}
	while (s2[b] != 0)
	{
		newstring[a] = s2[b];
		a++;
		b++;
	}
	newstring[a] = 0;
	return (newstring);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	result;
	int	mincounter;

	a = 0;
	result = 0;
	mincounter = 1;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == '\n')
		a++;
	if ((str[a] == '+') || (str[a] == '-'))
	{
		if (str[a] == '-')
			mincounter = mincounter * -1;
		a++;
	}
	while (str[a] != '\0' && ft_isdigit(str[a]) == 1)
	{
		result = (result * 10);
		result = (result + (str[a] - '0'));
		a++;
	}
	return (result * mincounter);
}

int	ft_isdigit(int c)
{
	int	a;

	a = 0;
	if (c >= '0' && c <= '9')
		a = 1;
	return (a);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (n == 0)
	{
		return (0);
	}
	a = 0;
	if (s1[a] == 0 && s2[a] == 0)
		return (0);
	while ((s1[a] != 0 || s2[a] != 0) && a < (n - 1) && s1[a] == s2[a])
		a++;
	return (((const unsigned char *)s1)[a] - ((const unsigned char *)s2)[a]);
}

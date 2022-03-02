/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftsplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ageels <ageels@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:50:33 by ageels            #+#    #+#             */
/*   Updated: 2022/02/14 16:57:56 by ageels           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdflib.h"

static void	ft_count(char const *s, char c, int *parts, int *c_c)
{
	int		i;

	i = 0;
	while (s[i] != 0 && s[i] == c)
	{
		i++;
		(*c_c)++;
	}
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			while (s[i] != 0 && s[i] == c)
			{
				i++;
				(*c_c)++;
			}
			if (s[i] == 0)
				return ;
			(*parts)++;
		}
		else
			i++;
	}
}

static void	ft_enter_data(void	*start_ptr, int f_len, char const *s, char c)
{
	int		i;
	int		j;
	int		skp;

	i = 0;
	j = 0;
	skp = 0;
	if (s[i] != c)
	{
		((char **)start_ptr)[j] = &((char *)start_ptr)[f_len];
		j++;
	}
	while (s[i] != 0)
	{
		if (s[i] == c && s[i] == s[i + 1] && s[i + 1] != '\0')
			skp++;
		if (s[i] == c && s[i] != s[i + 1] && s[i + 1] != '\0')
		{
			((char **)start_ptr)[j] = &((char *)start_ptr)[i + f_len + 1 - skp];
			j++;
		}
		else if (s[i] != c)
			((char *)start_ptr)[i + f_len - skp] = s[i];
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		f_len;
	int		c_c;
	void	*start_ptr;
	int		parts;

	parts = 1;
	c_c = 0;
	ft_count(s, c, &parts, &c_c);
	f_len = sizeof(char *) * (parts + 1);
	start_ptr = ft_calloc((f_len + ft_strlen(s) - c_c + parts), 1);
	if (start_ptr == 0)
		return (NULL);
	if (*s == '\0')
	{
		((char **)start_ptr)[0] = NULL;
		return ((char **)start_ptr);
	}
	ft_enter_data(start_ptr, f_len, s, c);
	return ((char **)start_ptr);
}

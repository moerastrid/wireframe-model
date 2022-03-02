/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 18:18:55 by ageels        #+#    #+#                 */
/*   Updated: 2022/02/25 14:32:30 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdflib.h"

unsigned int	ft_make_color(int r, int g, int b)
{
	return ((unsigned int)(r << 24 | g << 16 | b << 8 | 0xFF));
}

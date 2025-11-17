/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gomandam <gomandam@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 02:20:50 by gomandam          #+#    #+#             */
/*   Updated: 2025/05/22 12:08:47 by gomandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	flood_fill.h

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif


//	flood_fill.c

#include "flood_fill.h"

static void	fill(char **tab, t_point size, t_point curr, char to_fill)
{
	if (curr.y < 0 || curr.y >= size.y || curr.x < 0 || curr.x >= size.x)
		return;
	if (tab[curr.y][curr.x] != to_fill || tab[curr.y][curr.x] == 'F')
		return;
	tab[curr.y][curr.x] = 'F';
	fill(tab, size, (t_point){curr.x - 1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x + 1, curr.y}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y - 1}, to_fill);
	fill(tab, size, (t_point){curr.x, curr.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char to_fill = tab[begin.y][begin.x];
	if (to_fill != 'F')
		fill(tab, size, begin, to_fill);
}

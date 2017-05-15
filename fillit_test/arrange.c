/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:07:28 by amansour          #+#    #+#             */
/*   Updated: 2017/05/15 15:57:13 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	cote (t_tetri *tetri)
{
	int	i;
	int y;
	int min;
	int pos;

	i = -1;
	while (++i < 4 && tetri->tab[i].b);
	y = i;
	i = -1;
	min = 3;
	while (min && ++i < y)
	{
		pos = 0;
		while (!(tetri->tab[i].b & (1 << pos)))
			++pos;
		if (min > pos)
			min = pos;
	}
	return ((y > (4 - min)) ? y : 4 - min);
}

void	ft_arrange(t_tetri **list)
{
	int		c;
	//t_tetri	*maillon;

	c = cote(*list);
}

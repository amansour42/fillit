/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:09:28 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 14:10:07 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			cote_element(t_tetri *tetri)
{
	int i;
	int min;
	int pos;

	i = -1;
	min = 0;
	while (++i < 4 && tetri->tab[i].b)
	{
		pos = 0;
		while (!(tetri->tab[i].b & (8 >> pos)))
			++pos;
		if (min < (4 - pos))
			min = 4 - pos;
	}
	return (min);
}

int			cote_list(t_tetri *list)
{
	int max;
	int i;

	max = 0;
	while (list)
	{
		i = -1;
		while (++i < 4)
			max = (max < list->tab[i].y && list->tab[i].b)
				? list->tab[i].y : max;
		list = list->next;
	}
	return (++max);
}

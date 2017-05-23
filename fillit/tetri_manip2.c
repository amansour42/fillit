/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manip2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:56:24 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 15:27:59 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*copy_t(t_tetri *maillon)
{
	t_tetri	*tetri;
	int		i;

	if ((tetri = (t_tetri*)malloc(sizeof(t_tetri))))
	{
		tetri->next = NULL;
		tetri->c = maillon->c;
		i = -1;
		while (++i < 4)
		{
			tetri->tab[i].b = maillon->tab[i].b;
			tetri->tab[i].y = maillon->tab[i].y;
		}
	}
	return (tetri);
}

t_tetri		*copy_l(t_tetri *list)
{
	t_tetri *result;

	result = NULL;
	while (list)
	{
		add(&result, copy_t(list));
		list = list->next;
	}
	return (result);
}

int			right_nozero(t_tetri *tetri)
{
	int min;
	int pos;
	int i;

	i = -1;
	min = 3;
	while (++i < 4 && tetri->tab[i].b)
	{
		pos = 0;
		while (!(tetri->tab[i].b & (1 << pos)))
			++pos;
		if (min > pos)
			min = pos;
	}
	return (min);
}

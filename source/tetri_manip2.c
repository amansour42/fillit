/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_manip2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:56:24 by amansour          #+#    #+#             */
/*   Updated: 2017/06/02 10:34:19 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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

void		already_exist(t_tetri *list)
{
	t_tetri *lst;
	t_tetri *maillon;
	int		i;

	lst = list;
	maillon = list->next;
	while (maillon)
	{
		while (!maillon->exist && list->c != maillon->c)
		{
			i = -1;
			while (++i < 4 && (maillon->tab[i].b == list->tab[i].b))
				;
			if (i == 4)
				maillon->exist = 1;
			list = list->next;
		}
		list = copy_l(lst);
		maillon = maillon->next;
	}
}

int			right_nozero(t_tetri *tetri)
{
	int max;
	int pos;
	int i;

	i = -1;
	max = 3;
	while (++i < 4 && tetri->tab[i].b)
	{
		pos = -1;
		while (!(tetri->tab[i].b & (1 << ++pos)))
			;
		if (max > pos)
			max = pos;
	}
	return (max);
}

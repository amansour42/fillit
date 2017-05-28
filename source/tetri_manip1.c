/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_fcts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:12:36 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 19:09:14 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			cmp_t(t_tetri *list, t_tetri *tetri)
{
	int result;

	result = 0;
	while (!result && list)
	{
		result = (tetri->c == list->c) ? 1 : 0;
		list = list->next;
	}
	return (result);
}

int			cmp_l(t_tetri *list1, t_tetri *list2)
{
	int result;

	result = 1;
	while (result && list2)
	{
		result = cmp_t(list1, list2);
		list2 = list2->next;
	}
	return (result);
}

void		decale(t_tetri *tetri, int nbr)
{
	int i;

	i = -1;
	if (!nbr)
		return ;
	if (nbr > 0)
		while (++i < 4)
			tetri->tab[i].b <<= nbr;
	else
		while (++i < 4)
			tetri->tab[i].b >>= (-nbr);
}

void        delete_current(t_tetri **list, t_tetri *current)
{
    if ((*list)->c == current->c)
        return ;
    while ((*list)->next && (((*list)->next)->c != current->c))
        *list = (*list)->next;
    (*list)->next = ((*list)->next)->next;
}

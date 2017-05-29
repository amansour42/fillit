/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:09:28 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 19:06:07 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int             cote_element(t_tetri *tetri)
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

void            verify_v(t_point *tab)
{
    int i;

    i = -1;
    while (++i < 4 && !(tab[i].b))
        ;
    while (i < 4 && tab[i].b)
        ++i;
    while (++i < 4 && !(tab[i].b))
        ;
    if (i < 4)
        ft_error();
}

t_tetri         *optimize(t_tetri *list)
{
    t_tetri *lst;
    t_tetri *maillon;
    t_tetri *result;
    int     i;

    if (!list || !list->next)
        return (list);
    lst = list;
    i = -1;
    result = copy_t(list);
    maillon = list->next;
    while (maillon)
    {
        while (list &&  i != 4 && list != maillon)
        {
            i = -1;
            while (++i < 4 && (maillon->tab[i].b == list->tab[i].b))
                ;
            if (i == 4)
                add(&result, copy_t(list));
            list = list->next;
        }
        list = copy_l(lst);
    maillon = maillon->next;
    }
    return (result);
}

t_tetri         *right_square(int test, t_tetri *list, t_tetri *result)
{
    t_tetri *list1;
    t_tetri *result1;
    int     index1;
    int     index2;

    index1 = 0;
    index2 = 0;
    list1 = copy_l(list);
    if (!test)
        return (result);
    if (test == -1)
        return (list);
    result1 = copy_l(result);
    while (!index1 && !index2 && list)
    {
        index1 = (list->c == 'A') ? 1 : 0;
        index2 = (result->c == 'A') ? 1 : 0;
        result = result->next;
        list = list->next;
    }
    if (index2)
        return (result1);
    return (list1);
}

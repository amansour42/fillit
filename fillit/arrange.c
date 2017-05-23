/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 19:07:28 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 14:20:57 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			sum(t_tetri *list, int ligne)
{
	int i;
	int sum;

	sum = 0;
	while (list)
	{
		i = -1;
		while (++i < 4 && list->tab[i].y != ligne)
			;
		sum = (i == 4) ? sum : sum + list->tab[i].b;
		list = list->next;
	}
	return (sum);
}

static int			check_rest(t_tetri **tetri, int start, t_tetri *one, int c)
{
	int result;
	int i;

	i = 1;
	(*tetri)->tab[0].y = start;
	result = 1;
	while (result && (*tetri)->tab[i].b)
	{
		result = (++start < c && bit_cmp(sum(one, start),
					(*tetri)->tab[i].b, c)) ? 1 : 0;
		(*tetri)->tab[i].y = start;
		++i;
	}
	while (i < 4)
		(*tetri)->tab[i++].y = ++start;
	return (result);
}

static t_tetri		*test(t_tetri *one, int ligne, t_tetri *two, int c)
{
	t_tetri	*list;
	int		nb;
	t_tetri	*maillon;
	int		nb_list;

	list = NULL;
	nb_list = sum(one, ligne);
	while (two)
	{
		maillon = copy_t(two);
		nb = (maillon->tab[0].b) >> right_nozero(maillon);
		decale(maillon, c - cote_element(maillon));
		while (maillon->tab[0].b >= nb &&
				!bit_cmp(nb_list, maillon->tab[0].b, c))
			decale(maillon, -1);
		if (maillon->tab[0].b >= nb && check_rest(&maillon, ligne, one, c))
			add(&list, maillon);
		two = two->next;
	}
	return (list);
}

int					arrange(t_tetri **list, t_tetri *tmp, int c)
{
	t_tetri	*result;
	t_tetri	*right;
	int		i;
	int		val;

	i = -1;
	while (++i < c && !cmp_l(*list, tmp))
	{
		right = test(*list, i, tmp, c);
		result = copy_l(*list);
		while (right)
		{
			if (cmp_t(*list, right))
				right = right->next;
			else
			{
				add(list, copy_t(right));
				val = arrange(list, tmp, c);
				*list = (val) ? *list : copy_l(result);
				right = (val) ? NULL : right->next;
			}
		}
	}
	return (cmp_l(*list, tmp));
}

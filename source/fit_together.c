/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:27:44 by amansour          #+#    #+#             */
/*   Updated: 2017/06/02 13:28:44 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int	big_square(t_tetri *list)
{
	int c;

	c = cote_element(list);
	while ((list = list->next))
		c = (c < cote_element(list)) ? cote_element(list) : c;
	return (c);
}

static int	research(t_tetri **c, int size, t_tetri *cpy_var, int *l)
{
	int		n;
	t_tetri	*cpy;

	cpy = cpy_list(*c);
	n = arrange(c, cpy_var, size);
	while (!n && ++size <= *l)
	{
		*c = cpy_tetri(cpy);
		decale(*c, size - cote_element(*c));
		n = arrange(c, cpy_var, size);
	}
	if (n)
		n = (size < *l) ? -1 : 1;
	if (size < *l)
		*l = size;
	return (n);
}

int			fit_together(t_tetri **list)
{
	t_tetri	*current;
	t_tetri	*result;
	t_tetri	*var;
	int		limit;

	var = cpy_list(*list);
	limit = 26 * 26;
	result = NULL;
	while (*list)
	{
		if (!(*list)->exist)
		{
			current = cpy_tetri(*list);
			decale(current, big_square(var) - cote_element(current));
			result = right_square(research(&current, big_square(var),
						cpy_list(var), &limit), current, result);
		}
		*list = (*list)->next;
	}
	*list = result;
	return (limit);
}

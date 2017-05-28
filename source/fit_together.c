/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_together.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 17:27:44 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 19:06:34 by amansour         ###   ########.fr       */
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

	cpy = copy_l(*c);
    n = arrange(c, cpy_var, size);
	while (!n && ++size < *l)
	{
        *c = copy_t(cpy);
        decale(*c, size - cote_element(*c));
        n = arrange(c, cpy_var, size); 
	}
	if (n)
		*l = size;
	return (n);
}

int         fit_together(t_tetri **list)
{
	t_tetri	*current;
	t_tetri	*result;
	t_tetri	*var;
	int		limit;

	var = copy_l(*list);
	limit = 26 * 26;
    result = NULL;
	while (*list && limit != big_square(var))
	{
        if (!(*list)->exist)
        {
		    current = copy_t(*list);
            decale(current, big_square(var) - cote_element(current));
		    if (research(&current, big_square(var), copy_l(var), &limit))
                result = copy_l(current);
        }
        *list = (*list)->next;
	}
    *list = result;
	return (limit);
}

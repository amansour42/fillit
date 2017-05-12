/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 09:00:21 by amansour          #+#    #+#             */
/*   Updated: 2017/05/12 18:30:49 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void		ft_add(t_tetri **ap, t_tetri *tetri)
{
	t_tetri *maillon;

	if (!tetri)
	{
		if (*ap)
			ft_free(ap);
		ft_error();
	}
	if (*ap)
	{
		maillon = *ap;
		while ((*ap)->next)
			*ap = (*ap)->next;
		(*ap)->next = tetri;
		*ap = maillon;
	}
	else
		*ap = tetri;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 09:00:21 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 15:24:29 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add(t_tetri **ap, t_tetri *tetri)
{
	t_tetri *maillon;

	if (!tetri)
	{
		if (*ap)
			free(ap);
		*ap = NULL;
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

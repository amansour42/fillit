/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 13:29:16 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 19:08:15 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	free_list(t_tetri **ap)
{
	t_tetri *maillon;

	if (ap)
	{
		while (*ap)
		{
			maillon = (*ap)->next;
			(*ap)->next = NULL;
			ft_memdel((void**)ap);
			ap = &maillon;
		}
	}
}

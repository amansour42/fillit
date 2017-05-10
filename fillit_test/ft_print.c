/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:54:15 by amansour          #+#    #+#             */
/*   Updated: 2017/05/10 18:53:04 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_print_tetri(t_tetri *tetri)
{
	char	*app;
	int		i;
	int		j;
	int		var;

	if ((app = (char*)malloc(sizeof(char) * 21)))
	{
		j = -1;
		i = -1;
		while (++j < 4)
		{
			var = 8;
			while (++i < (4 * (j + 1) + j))
			{
			app[i] = (tetri->tab[j] & var) ? tetri->c : '.';
				var = var >> 1;
			}
		}
		app[20] = '\0';
		ft_putstr(app);
		ft_strdel(&app);
	}
}

void		ft_print(t_tetri *tetri)
{
	while (tetri->next)
	{
		ft_print_tetri(tetri);
		tetri = tetri->next;
		ft_putchar('\n');
	}
	ft_print_tetri(tetri);
}

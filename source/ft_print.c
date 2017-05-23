/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:54:15 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 20:06:26 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	initialisation(char **str, int size)
{
	int i;

	i = -1;
	while (++i < size)
		str[0][i] = '.';
	str[0][i] = '\0';
}

static void	print_ligne(t_tetri *tetri, int ligne, int size)
{
	char	*app;
	int		i;
	int		j;

	if ((app = (char*)malloc(sizeof(char) * (size + 1))))
	{
		initialisation(&app, size);
		while (tetri)
		{
			i = -1;
			while (++i < 4 && (tetri->tab[i].y != ligne))
				;
			if (i != 4 && tetri->tab[i].b)
			{
				j = -1;
				while (++j < size)
					if ((1 << j) & tetri->tab[i].b)
						app[size - j - 1] = tetri->c;
			}
			tetri = tetri->next;
		}
		ft_putstr(app);
		ft_strdel(&app);
	}
}

void		print(t_tetri *tetri, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		print_ligne(tetri, i, size);
		if (i < (size - 1))
			ft_putchar('\n');
	}
}

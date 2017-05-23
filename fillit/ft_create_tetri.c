/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:43:18 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 15:26:23 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	verification du buffer :
**	1- 4 lignes et chaque ligne contient soit des # ou des .
**	2- verification du contact vertical des dieses ainsi que leur nombre 4
*/

static void			ndiese(char **l)
{
	int nd;
	int i;
	int j;
	int p;

	nd = 0;
	i = 0;
	while (l[i] && i < 4)
	{
		j = -1;
		p = -1;
		while (l[i][++j] && (l[i][j] == '#' || l[i][j] == '.'))
		{
			if (l[i][j] == '#')
			{
				(p != -1 && (j - p) != 1) ? ft_error() : ++nd;
				p = j;
			}
		}
		(j != 4) ? ft_error() : ++i;
	}
	if (nd > 4)
		ft_error();
}

/*
**	Remplissage du tab du tetri avec verification du contact
**	vertical des dieses
*/

static void			fill(t_point **tab, char **l)
{
	int		i;
	int		j;
	int		nb;
	int		bits;

	i = -1;
	bits = 0;
	nb = 0;
	while (++i < 4)
	{
		(*tab)[i].y = i;
		j = -1;
		(*tab)[i].b = 0;
		while (++j < 4)
		{
			(*tab)[i].b <<= 1;
			if (l[i][j] == '#')
				(*tab)[i].b += 1;
		}
		if (nb && (*tab)[i].b && !((*tab)[i].b & nb))
			ft_error();
		nb = (*tab)[i].b;
	}
}

/*
**	creation d'un tetri
*/

t_tetri				*create_tetri(char *buffer, char a)
{
	t_point	*tmp;
	t_tetri *maillon;
	char	**lines;
	int		i;

	if (!(lines = ft_strsplit(buffer, '\n')))
		return (NULL);
	ndiese(lines);
	if ((maillon = (t_tetri*)malloc(sizeof(t_tetri)))
			&& (tmp = (t_point*)malloc(sizeof(t_point) * 4)))
	{
		i = -1;
		while (++i < 4)
			tmp[i].b = 0;
		fill(&tmp, lines);
		maillon->next = NULL;
		maillon->c = a;
		i = -1;
		while (++i < 4)
			maillon->tab[i] = tmp[i];
		return (maillon);
	}
	return (NULL);
}

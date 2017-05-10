/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 20:43:18 by amansour          #+#    #+#             */
/*   Updated: 2017/05/10 18:44:08 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
 * verification du buffer :
 * 1- 4 lignes et chaque ligne contient soit des # ou des .
 * 2- verification du contact vertical des dieses ainsi que leur nombre 4
 */
static void				ft_ndiese(char **l)
{
	int ndiese;
	int i;
	int j;
	int pos;

	ndiese = 0;
	i = 0;
	while (l[i] && i < 4)
	{
		j = -1;
		pos = -1;
		while(l[i][++j] && (l[i][j] == '#' || l[i][j] == '.'))
		{
			if (l[i][j] == '#')
			{
				(pos != -1 && (j - pos != 1)) ? ft_error() : ++ndiese;
				pos = j;
			}
		}
		(j != 4 || ndiese > 4) ? ft_error() : ++i;
	}
	if (i < 4 || l[i] || ndiese < 4)
		ft_error();
}
/*
 * Remplissage du tab du tetri avec verification du contact
 * vertical des dieses
 */
static void					ft_fill(int **tab, char **l)
{
	int		i;
	int		j;
	int		nb;
	int		bits;

	i = -1;
	bits = 0;
	nb = 0;
	while (++i < 4 && bits < 4) 
	{
		j = -1;
		while (++j < 4)
		{
			tab[0][i] *= 2;
			if (l[i][j] == '#')
			{
				++bits;
				tab[0][i] += 1;
			}
		}	
		if (nb && !(nb & tab[0][i]))
			ft_error();
		nb = tab[0][i];
	}
}
/*
 * creation d'un tetri
 */

t_tetri							*ft_create_tetri(char *buffer, char a)
{
	int		*tmp;
	t_tetri *maillon;
	char	**lines;
	int		i;

	i = -1;
	if (!(lines = ft_strsplit(buffer, '\n')))
			return (NULL);
	ft_ndiese(lines);
	if ((maillon = (t_tetri*)malloc(sizeof(t_tetri))) &&
			(tmp = (int*)malloc(sizeof(int) * 4))) 
	{
		while (++i < 4)
			tmp[i] = 0;
		ft_fill(&tmp, lines);
		maillon->next = NULL;
		maillon->c = a;
		i = -1;
		while (++i < 4)
			maillon->tab[i] = tmp[i];
		free((void*)tmp);
		return (maillon);
	}
	return (NULL);
}

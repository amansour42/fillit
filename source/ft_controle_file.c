/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controle_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:51:42 by amansour          #+#    #+#             */
/*   Updated: 2017/06/02 10:26:40 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
**	lecture du fichier et creation de list de tetri au meme tmps
**	decalage des dieses de chaque tetri le plus haut
**	et le plus a guche possible
*/

static int			decale_v(t_tetri *list, int pos)
{
	int i;
	int result;

	i = pos - 1;
	while (list->tab[++i].b && i < 4)
		list->tab[i - pos].b = list->tab[i].b;
	pos = i - pos - 1;
	result = pos + 1;
	while (++pos < 4)
		list->tab[pos].b = 0;
	return (result);
}

static void			decale_h(t_tetri *list, int end)
{
	int i;
	int pos;
	int max;

	i = -1;
	max = 3;
	if (end == 1)
		return ;
	decale(list, -1 * right_nozero(list));
	while (++i < end)
	{
		pos = -1;
		while (!(list->tab[i].b & (8 >> ++pos)))
			;
		if (max > pos)
			max = pos;
	}
	if (end > (4 - max))
		decale(list, end - 4 + max);
}

static void			edit_tab(t_tetri **list)
{
	int		i;
	t_tetri	*lst;

	lst = *list;
	while (*list)
	{
		i = -1;
		while (++i < 4 && !((*list)->tab[i].b))
			;
		decale_h(*list, decale_v(*list, i));
		*list = (*list)->next;
	}
	*list = lst;
}

void				controle_file(int fd, t_tetri **list)
{
	char	*buffer;
	char	c;
	int		n_read;

	c = 'A';
	*list = NULL;
	if ((buffer = (char*)malloc(BUFF_SIZE)))
	{
		while ((n_read = read(fd, buffer, BUFF_SIZE)) == BUFF_SIZE)
		{
			if (buffer[0] == '\n')
			{
				ft_strdel(&buffer);
				free_list(list);
				ft_error();
			}
			add(list, create_tetri(buffer, c++));
		}
		(n_read != 20) ? ft_error() : add(list, create_tetri(buffer, c));
		ft_strdel(&buffer);
		edit_tab(list);
		already_exist(*list);
	}
}

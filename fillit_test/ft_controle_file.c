/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controle_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:51:42 by amansour          #+#    #+#             */
/*   Updated: 2017/05/15 17:18:48 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	lecture du fichier et creation de list de tetri au meme tmps
**	decalage des dieses de chaque tetri le plus haut
**	et le plus a guche possible
*/

static int			decale_v(t_tetri **list, int pos)
{
	int i;
	int result;

	i = pos - 1;
	while ((*list)->tab[++i].b && i < 4)
		(*list)->tab[i - pos].b = (*list)->tab[i].b;
	pos = i - pos - 1;
	result = pos + 1;
	while (++pos < 4)
		(*list)->tab[pos].b = 0;
	return (result);
}

static void			decale_h(t_tetri **list, int end)
{
	int i;
	int pos;
	int max;

	i = -1;
	max = 3;
	while (++i < end)
	{
		pos = 0;
		while (pos < max && !((*list)->tab[i].b & (1 << pos)))
			++pos;
		if (max > pos)
			max = pos;
	}
	i = -1;
	if (end > max)
		max = end - max;
	while (++i < end)
		(*list)->tab[i].b >>= max;
}

static void			edit_tab(t_tetri **list)
{
	int		i;
	t_tetri	*lst;
	t_tetri *previous;

	lst = NULL;
	while (*list)
	{
		i = -1;
		while (++i < 4 && !(*list->tab[i].b))
			;
		if (decale_v(list, i) != 1)
			decale_h(list, i);
		if (!lst)
		{
			lst = *list;
			previous = *list;
		}
		else
		{
			previous->next = *list;
			previous = *list;
		}
		*list = (*list)->next;
	}
	list = &lst;
}

void				ft_controle_file(int fd, t_tetri **list)
{
	char	*buffer;
	char	c;
	int		ntetri;

	c = 'A';
	ntetri = 0;
	if (!(buffer = (char*)malloc(BUFF_SIZE)))
		return ;
	*list = NULL;
	while (read(fd, buffer, BUFF_SIZE))
	{
		++ntetri;
		if (buffer[0] == '\n')
		{
			ft_strdel(&buffer);
			ft_free(list);
			ft_error(0);
		}
		ft_add(list, ft_create_tetri(buffer, c++));
	}
	if (ntetri == 1 && buffer[20])
		ft_error(1);
	ft_strdel(&buffer);
	edit_tab(list);
}

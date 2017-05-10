/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controle_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:51:42 by amansour          #+#    #+#             */
/*   Updated: 2017/05/10 18:40:14 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_controle_file(int fd, t_tetri **list)
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
		++ntetri;;
		if (buffer[0] == '\n')
		{
			ft_strdel(&buffer);
			ft_free(list);
			printf("ERREUR : retour a la ligne au moins en plus\n");
			ft_error();
		}
		ft_add(list, ft_create_tetri(buffer, c++));
	}
	if (ntetri == 1 && buffer[20])
	{
		printf("ERREUR : 1seul tetri qui se termine par un retour a la ligne");
		ft_error();
	}
	ft_strdel(&buffer);
}

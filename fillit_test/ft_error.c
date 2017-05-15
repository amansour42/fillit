/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:46:52 by amansour          #+#    #+#             */
/*   Updated: 2017/05/15 16:55:21 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(int n)
{
	if (n == 0)
		ft_putendl("0 : retour a la ligne au moins en +");
	else if (n == 1)
		ft_putendl("1 : 1 seul tetri qui se termine par un retour a la ligne");
	else if (n == 2)
		ft_putendl("2 : diese pas en contact horizontal");
	else if (n == 3)
		ft_putendl("3 : une ligne ne contient soit moins ou + de 4");
	else if (n == 4)
		ft_putendl("4 : nbre de dieses different de 4");
	else if (n == 5)
		ft_putendl("5 : pas de contact vertical des tetri");
	else
		ft_putendl("6 : retour null de ft_create_tetri");
	exit(0);
}

int		ft_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(0);
	return (0);
}

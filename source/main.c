/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:54:09 by amansour          #+#    #+#             */
/*   Updated: 2017/06/02 10:30:07 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tetri	*lst;
	int		dimension;

	lst = NULL;
	if (argc != 2)
		usage();
	if ((fd = open(argv[1], O_RDONLY)) != -1 &&
			(lst = (t_tetri*)malloc(sizeof(*lst))))
		controle_file(fd, &lst);
	if (lst)
	{
		dimension = fit_together(&lst);
		print(lst, dimension);
		free((void*)lst);
	}
	return (0);
}

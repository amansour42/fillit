/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:54:09 by amansour          #+#    #+#             */
/*   Updated: 2017/05/15 16:54:06 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_tetri	*lst;

	lst = NULL;
	if (argc != 2)
		ft_usage();
	if ((fd = open(argv[1], O_RDONLY)) != -1 &&
			(lst = (t_tetri*)malloc(sizeof(*lst))))
		ft_controle_file(fd, &lst);
	if (lst)
		ft_print(lst);
	free((void*)lst);
	return (0);
}

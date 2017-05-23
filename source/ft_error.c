/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:46:52 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 19:07:54 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_error(void)
{
	exit(0);
}

int		usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(0);
	return (0);
}

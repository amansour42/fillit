/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:46:52 by amansour          #+#    #+#             */
/*   Updated: 2017/05/12 18:29:52 by qdurot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

int		ft_usage(void)
{
	ft_putendl("usage: ./fillit source_file");
	exit(0);
	return (0);
}

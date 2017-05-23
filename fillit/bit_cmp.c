/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:52:48 by amansour          #+#    #+#             */
/*   Updated: 2017/05/23 13:53:13 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	bit_cmp(int a, int b, int size)
{
	int i;
	int result;

	i = 1 << size;
	result = 1;
	while (!(b & i))
		i >>= 1;
	while (result && i && (b & i))
	{
		result = (!(a & i)) ? 1 : 0;
		i >>= 1;
	}
	return (result);
}

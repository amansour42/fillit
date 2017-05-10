/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:08:16 by amansour          #+#    #+#             */
/*   Updated: 2017/05/10 14:47:00 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../libft_test/libft.h"
# define BUFF_SIZE 21

typedef struct		s_tetri
{
	char			c;
	int				tab[4];
	struct s_tetri	*next;
}					t_tetri;

int					main(int argc, char **argv);
void				ft_error();
int					ft_usage();
void				ft_controle_file(int fd, t_tetri **list);
t_tetri				*ft_create_tetri(char *buffer, char a);
void				ft_add(t_tetri **ap, t_tetri *tetri);
void				ft_print(t_tetri *tetri);
void				ft_free(t_tetri **ap);
#endif

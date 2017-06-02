/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:08:16 by amansour          #+#    #+#             */
/*   Updated: 2017/06/02 13:33:05 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define BUFF_SIZE 21

typedef struct		s_point
{
	int				b;
	int				y;
}					t_point;

typedef struct		s_tetri
{
	char			c;
	t_point			tab[4];
	struct s_tetri	*next;
	int				exist;
}					t_tetri;

int					main(int argc, char **argv);
void				ft_error(void);
void				usage(void);
void				controle_file(int fd, t_tetri **list);
t_tetri				*create_tetri(char *buffer, char a);
t_tetri				*cpy_tetri(t_tetri *maillon);
t_tetri				*cpy_list(t_tetri *maillon);
t_tetri				*optimize(t_tetri *list);
t_tetri				*right_square(int test, t_tetri *list, t_tetri *result);
void				add(t_tetri **ap, t_tetri *tetri);
void				print(t_tetri *tetri, int c);
void				free_list(t_tetri **ap);
int					arrange(t_tetri **tetri, t_tetri *tmp, int c);
int					fit_together(t_tetri **list);
int					cote_element(t_tetri *tetri);
int					bit_cmp(int a, int b, int a_size);
int					cmp_t(t_tetri *list, t_tetri *tetri);
int					cmp_l(t_tetri *list1, t_tetri *list2);
void				decale(t_tetri *tetri, int nbr);
void				already_exist(t_tetri *list);
void				verify_v(t_point *tab);
int					right_nozero(t_tetri *tetri);
#endif

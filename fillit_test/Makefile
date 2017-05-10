# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:46:13 by amansour          #+#    #+#              #
#    Updated: 2017/05/10 14:17:13 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFLAGS = -L ../libft_test -lft

FLAGS = -Wall -Wextra -Werror

SRC = main.c ft_controle_file.c ft_create_tetri.c ft_add.c ft_print.c\
	  ft_free.c ft_error.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

INCLUDS = ../libft_test/libft.h

INCLUD = fillit.h

all: $(NAME)

$(LIB):
	make -C ../libft_test

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(OBJ) $(LIBFLAGS) -o $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC) -I $(INCLUDS) -I $(INCLUD)

clean:
	rm -rf $(OBJ)
	make -C ../libft_test clean

fclean: clean
	rm -f $(NAME)
	make -C ../libft_test fclean

re: fclean all

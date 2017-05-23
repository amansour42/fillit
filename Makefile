# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:46:13 by amansour          #+#    #+#              #
#    Updated: 2017/05/23 20:57:57 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./source
OBJ_PATH = ./obj
INCLUD  = ./includes
LIB = libft/libft.a

SRC = arrange.c dimension.c fit_together.c\
	  ft_controle_file.c ft_error.c ft_print.c\
	  tetri_manip1.c bit_cmp.c ft_add.c ft_create_tetri.c\
	  ft_free.c main.c tetri_manip2.c

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(LIB):
	@make -C libft

#extra:
#	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amansour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 18:46:13 by amansour          #+#    #+#              #
#    Updated: 2017/05/23 20:08:22 by amansour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LDFLAGS = -L libft
LDLIBS = -lft
FLAGS = -Werror -Wall -Wextra

SRC_PATH = ./source
OBJ_PATH = ./obj
INCLUD  = ./includes

SRC = arrange.c dimension.c fit_together.c\
	  ft_controle_file.c ft_error.c ft_print.c\
	  tetri_manip1.c bit_cmp.c ft_add.c ft_create_tetri.c\
	  ft_free.c main.c tetri_manip2.c

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

all:

	mkdir -p $(OBJ_PATH)
	@$(MAKE) -C libft  --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		gcc $(FLAGS) -I $(INCLUD) -o $@ -c $<

$(NAME): $(OBJ)
		gcc $(OBJ) $(LDFLAGS) $(LDLIBS) -o $(NAME)

clean:
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -rf $(NAME)

re:
		@$(MAKE) fclean --no-print-directory
		@$(MAKE) all --no-print-directory

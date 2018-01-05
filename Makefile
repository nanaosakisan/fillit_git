# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arusso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 13:46:59 by arusso            #+#    #+#              #
#    Updated: 2017/12/22 11:35:39 by iporsenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./
SRC_NAME =	main.c				\
			fonction_aux.c		\
			fonction_check_1.c	\
			fonction_check_2.c	\
			fonction_init.c		\
			free.c				\
			parsing.c			\
			solveur.c

SRC	= $(addprefix $(SRC_PATH), $(SRC_NAME))

INCLUDE_PATH = ./
INCLUDE_NAME = fillit.h
INCLUDE	= $(addprefix $(INCLUDE_PATH), $(INCLUDE_NAME))

HEADER_PATH = ./libft/
HEADER_NAME = libft.a
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))

OBJ	= $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft
	gcc $(FLAGS) $(SRC) $(HEADER) -o $(NAME)


clean :
	make clean -C libft
	rm -f $(OBJ)

fclean : clean
	make fclean -C libft
	rm -f $(NAME)

re : fclean all

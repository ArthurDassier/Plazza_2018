##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro-matic
##

NAME		=	plazza

SRC			= 	srcs/main.cpp				\
				srcs/Cook.cpp				\
				srcs/Kitchen.cpp			\
				srcs/Reception.cpp			\
				srcs/Parser.cpp

OBJ			=	$(SRC:.cpp=.o)

MY.H_DIR	=	./includes

CC			=	g++

CFLAGS		=	-Wextra -Wall -g3

CPPFLAGS	=	-I$(MY.H_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean

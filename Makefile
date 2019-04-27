##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for bistro-matic
##

NAME		=	plazza

TEST_NAME	=	unit_test_plazza

SRC			= 	srcs/main.cpp				\
				srcs/Cook.cpp				\
				srcs/Kitchen.cpp			\
				srcs/Reception.cpp			\

OBJ			=	$(SRC:.cpp=.o)

SRC_TEST	= tests/tests_Kitchen.cpp		\

OBJ_TEST	= $(SRC_TEST:.cpp=.o)

MY.H_DIR	=	./includes

CC			=	g++

CFLAGS		=	-Wextra -Wall -g3

CPPFLAGS	=	-I$(MY.H_DIR) -std=c++17

UNITS_FLAGQ	=	-coverage -lcriterion

all: $(NAME)
	$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

tests_run:
	$(CC) -o $(TEST_NAME) $(UNITS_FLAGQ) $(OBJ_TEST)
	./$(TEST_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean

##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile for plazza
##

NAME		=	plazza

CXX			=	g++ -std=c++17 -g3 -pthread

TEST_NAME	=	unit_test_plazza

SRC_DIR		=	./srcs

UT_DIR		=	./tests

EXE			= 	$(SRC_DIR)/main.cpp				\
				$(SRC_DIR)/Cook.cpp				\
				$(SRC_DIR)/Kitchen.cpp			\
				$(SRC_DIR)/Reception.cpp		\
				$(SRC_DIR)/Parser.cpp			\
				$(SRC_DIR)/PlazzaError.cpp		\
				$(SRC_DIR)/EncapsThread.cpp		\

OBJS		=	$(EXE:.cpp=.o)

UT 			= 	$(UT_DIR)/tests_Reception.cpp	\
				$(UT_DIR)/tests_Parser.cpp		\
				$(UT_DIR)/tests_Cook.cpp		\
				$(UT_DIR)/tests_Kitchen.cpp		\

UT2			=	$(SRC_DIR)/Cook.cpp				\
				$(SRC_DIR)/Kitchen.cpp			\
				$(SRC_DIR)/Reception.cpp		\
				$(SRC_DIR)/Parser.cpp			\
				$(SRC_DIR)/PlazzaError.cpp

OBJS_UT		=	$(UT:.cpp=.o)

OBJS_UT2	=	$(UT2:.cpp=.o)

RM			=	rm -rf

CXXFLAGS	=	-Wall -Wextra 

CXXFLAGS	+=	-I ./includes

INCLUDE		=	-I ./includes

LD_FLAGS	=	-lcriterion -coverage -pthread

all:		$(NAME)

$(NAME): $(OBJS) 
		$(CXX) $(INCLUDE) -o $(NAME) $(OBJS)


tests_run:	$(OBJS) 
			g++ -std=c++17 $(INCLUDE) -o UT $(UT) $(UT2) $(LD_FLAGS)
			./UT

clean:
		$(RM) $(OBJS)

ut_clean:
		$(RM) $(OBJS_UT) $(OBJS_UT2)
		find \( -name "*.gc*" -o -name "#*#" \) -delete
		$(RM) UT

fclean:		clean ut_clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		re all fclean clean tests_run ut_clean

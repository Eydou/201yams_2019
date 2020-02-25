##
## EPITECH PROJECT, 2019
## minishell1
## File description:
## Makefile
##

SRC	=	$(shell find ./ -name '*.cpp' ! -name unit_test.cpp)	\

OBJ	=	$(SRC:.c=.o)

TEST	=	$(shell find ./ -name '*.cpp' ! -name 'main.cpp')	\

CC	=	g++ -I./include

NAME	=	201yams

CPP_FLAGS	=	-W -Wall -Werror -Wextra -std=c++11

all:	$(NAME)

tests_run:	$(TEST)
	$(CC) -o unit_tests $(TEST) -lcriterion --coverage
	./unit_tests | gcovr

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CPP_FLAGS) $(OBJ)
clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*#')
	rm -f $(shell find $(SOURCEDIR) -name '*vg*')
	rm -f $(shell find $(SOURCEDIR) -name '*.gc*')


fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all tests_run clean fclean re

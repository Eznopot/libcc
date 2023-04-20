##
## EPITECH PROJECT, 2018
## bsq
## File description:
## bsq
##

SRC =	main.c \
		../my_strlen.c \
		../str_to_array.c \
		../string/string.c \
		../vector/vector.c \
		../list/list.c \

COMP =	gcc -g3

OBJ =	$(SRC:.c=.o)

NAME	=	test

CFLAG	=	-o

all:	$(NAME)

$(NAME):	$(OBJ)
	$(COMP) $(SRC) $(CFLAG) $(NAME) -ldl
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: all clean
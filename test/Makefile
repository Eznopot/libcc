##
## EPITECH PROJECT, 2018
## bsq
## File description:
## bsq
##

MAIN =	main.c

MAIN_list =	main_list.c

MAIN_vector =	main_vector.c

SRC =	../my_strlen.c \
		../str_to_array.c \
		../string/string.c \
		../vector/vector.c \
		../list/list.c \

COMP =	gcc -g3

OBJ =	$(SRC:.c=.o)

NAME	=	test

CFLAG	=	-o

all:	$(NAME) list vector

$(NAME):	$(OBJ)
	$(COMP) $(SRC) $(MAIN) $(CFLAG) $(NAME) -ldl
	rm -f $(OBJ)

list:	$(OBJ)
	$(COMP) $(SRC) $(MAIN_list) $(CFLAG) list -ldl
	rm -f $(OBJ)

vector:	$(OBJ)
	$(COMP) $(SRC) $(MAIN_vector) $(CFLAG) vector -ldl
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f list
	rm -f vector

re: all clean
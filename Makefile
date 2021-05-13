##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile to compile the project
##

CC	=	gcc

SRC	=	$(wildcard src/*.c)

OBJ	 =	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall -Wextra -Werror -I./includes

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all
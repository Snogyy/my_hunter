##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## EPITECH
##

SRC 	=	myhunter.c \
			manage_sprite.c \
			candy.c \
			events.c \
			clock.c \
			score_to_str.c

NAME 	= 	myhunter

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -g

clean :

fclean: clean
	rm $(NAME)

re: fclean all

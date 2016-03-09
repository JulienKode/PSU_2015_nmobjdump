##
## Makefile for  in /home/karst_j/rendu/B1/Prog Elem/CPE_2014_bsq
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Mon Dec 22 13:25:12 2014 Julien Karst
## Last update Sun Feb 28 15:01:20 2016 Julien Karst
##

$(info ************  MyNm ************)

NAME	= my_nm

CC	= gcc

CFLAGS	= -I./includes

SRC	= 		sources/main.c		\
			sources/nm.c		\
			sources/check.c		\
			sources/error.c		\
			sources/x86-64.c		\
			sources/get_symtab.c	\
			sources/nm_action.c	\
			sources/nm_action_32.c	\
			sources/display.c \
			sources/sort.c \
			sources/sort_sym.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -Ofast -Wall -pedantic -ansi
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

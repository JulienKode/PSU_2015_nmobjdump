##
## Makefile for  in /home/karst_j/rendu/B1/Prog Elem/CPE_2014_bsq
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Mon Dec 22 13:25:12 2014 Julien Karst
## Last update Mar 1 15:27:17 2016 Julien Karst
##

$(info ************  MyObjdump ************)

NAME	= my_objdump

CC		= gcc

CFLAGS	= -I./includes

SRC	= 	sources/check.c					\
		sources/print.c 				\
		sources/print_function.c 		\
		sources/print2.c 				\
		sources/print2_32.c				\
		sources/print3.c 				\
		sources/print3_32.c				\
		sources/objdump.c 				\
		sources/check_option.c			\
		sources/error.c					\
		sources/x86-64.c				\
		sources/main.c

OBJ	= $(SRC:.c=.o)

LDFLAGS	= -L./lib -lmy

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) -g -Ofast -Wall -Wextra -pedantic -ansi
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re

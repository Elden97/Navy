##
## Makefile for Makefile in /home/Elden/Desktop/tech1/PSU_2016_my_printf
## 
## Made by Eythan Fellous
## Login   <Elden@epitech.net>
## 
## Started on  Wed Nov  9 21:30:11 2016 Eythan Fellous
## Last update Mon Jan 30 14:50:42 2017 Eythan Fellous
##

CC = gcc -g

RM = rm -f

AR = ar rc

NAME =	libmy.a

SRCS =	root.c \
	print_char.c \
	print_dig.c \
	strint.c \
	binaire.c \
	printest.c \
	print_base.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	 $(AR) $(NAME) $(OBJS)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

##
## Makefile for Navy in /home/groot/Documents/Navy/WIP
## 
## Made by Groot
## Login   <magali.denelle@epitech.eu>
## 
## Started on  Mon Feb 13 11:35:24 2017 Groot
## Last update Sun Feb 19 21:04:17 2017 Groot
##

CC	=	gcc

RM	=	rm -f
R	=	rm *~

CFLAGS	=	-I./include

NAME	=	navy

SRCS	=	create_maps.c		\
		game_start.c		\
		display.c		\
		main.c			\
		place_boats.c		\
		tools.c			\
		get_next_line.c		\
		my_getnbr.c		\
		encode_decode.c		\
		connect_players.c	\
		input.c			\
		attack_defend.c		\
		receive_send.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):$(OBJS)
	make -C ./library
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) -L ./library -lmy

clean:
	make -C ./library clean
	$(RM) $(OBJS)

fclean:
	make -C ./library fclean
	$(RM) $(NAME) $(OBJS)

re:	fclean all

.PHONY:	all clean fclean re

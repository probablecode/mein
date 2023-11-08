# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 21:38:32 by jchoi             #+#    #+#              #
#    Updated: 2022/06/26 22:42:03 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= $(CLIENT) $(SERVER)
CLIENT		=	client
SERVER		=	server
CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror
SOURCES		=	client.c server.c
OBJECTS		=	$(SOURCES:.c=.o)
LIBFT		= ./libft/libft.a
HD			= ./libft/libft.h
INCLUDE		= $(LIBFT)

all			:	$(NAME)

$(SERVER)		: $(LIBFT)
		$(CC) $(CCFLAG) -o $@ server.c $(LIBFT)

$(CLIENT)		: $(LIBFT)
		$(CC) $(CCFLAG) -o $@ client.c $(LIBFT)

$(LIBFT) :
	make -C ./libft/

%.o : %.c
		$(CC) $(CCFLAG) -c $<

clean		:
		rm -rf $(OBJECTS)

fclean		:	clean
		rm -rf $(CLIENT) $(SERVER)

re			:	fclean all

.PHONY		:	all clean fclean re

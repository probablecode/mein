# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 16:43:02 by jchoi             #+#    #+#              #
#    Updated: 2022/12/23 15:10:58 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror
DEFOPT		=	-D WIDTH=1920 -D HEIGHT=1080 -D MAG=4 -D BUFFER_SIZE=42
MLXOPT		=	-lmlx -framework OpenGL -framework AppKit

HD			= 	./fdf.h
LIBFT		=	./libft/libft.a
OBJECTS		=	$(SOURCES:.c=.o)
SOURCES		=	fdf_input.c\
				fdf_process.c\
				fdf_utils.c\
				fdf.c\

all			:	$(NAME)

$(NAME)	: $(OBJECTS) $(LIBFT)
	$(CC) $(CCFLAG) $(MLXOPT) -o $@ $^

$(LIBFT) :
	make bonus -C ./libft/

%.o : %.c
	$(CC) $(CCFLAG) -include $(HD) $(DEFOPT) -c $<

clean	:
	rm -rf $(OBJECTS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all


.PHONY	:	all clean fclean re

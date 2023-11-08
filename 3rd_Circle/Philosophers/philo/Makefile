# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 21:38:32 by jchoi             #+#    #+#              #
#    Updated: 2022/09/06 15:42:49 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	philo
CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror
SOURCES		=	ph_main.c\
				ph_init.c\
				ph_term.c\
				ph_monitor.c\
				ph_routine.c\
				ph_action.c\
				ph_utils.c\
				ph_atoi.c

HD			= 	philo.h

OBJECTS		=	$(SOURCES:.c=.o)

all			:	$(NAME)

$(NAME)	: $(OBJECTS)
		$(CC) $(CCFLAG) -o $@ $^

%.o : %.c
	$(CC) $(CCFLAG) -include $(HD) -c $<

clean	:
	rm -rf $(OBJECTS)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

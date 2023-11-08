# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/26 21:38:32 by jchoi             #+#    #+#              #
#    Updated: 2022/07/17 17:16:27 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS		= checker
CC			=	cc
CCFLAG		=	-Wall -Wextra -Werror
SOURCES		=	circular_list.c\
				circular_stack.c\
				ps_stack.c\
				ps_input.c\
				ps_sort.c\
				ps_hsort.c\
				push_swap.c

BN_SOURCES	=	push_swap_bonus.c\
				ps_stack_bonus.c\
				ps_input_bonus.c\
				circular_list_bonus.c\
				circular_stack_bonus.c

OBJECTS		=	$(SOURCES:.c=.o)
BN_OBJECTS	=	$(BN_SOURCES:.c=.o)

HD			= 	push_swap_bonus.h\

LIBFT		= ./libft/libft.a

all			:	$(NAME)

$(NAME)	: $(OBJECTS) $(LIBFT)
		$(CC) $(CCFLAG) -o $@ $^

$(BONUS) : $(BN_OBJECTS) $(LIBFT)
		$(CC) $(CCFLAG) -o $@ $^
$(LIBFT) :
	make bonus -C ./libft/

%.o : %.c
	$(CC) $(CCFLAG) -include $(HD) -c $<

clean	:
	rm -rf $(OBJECTS) $(BN_OBJECTS)

fclean	:	clean
	rm -rf $(NAME) $(BONUS)

re		:	fclean all

bonus	:	$(BONUS)

.PHONY	:	all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 19:32:15 by jchoi             #+#    #+#              #
#    Updated: 2022/06/26 22:39:46 by jchoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm
RMFLAGS = -f
AR		= ar
ARFLAGS = crs
INCLUDES	= ./libft.h 

SRCS_1	= ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_strlen.c\
		  ft_memset.c\
		  ft_bzero.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strncmp.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strnstr.c\
		  ft_calloc.c\
		  ft_strdup.c\
		  ft_atoi.c
		  
SRCS_2	= ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_striteri.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c

SRCS_BN = ft_lstnew.c\
		  ft_lstadd_front.c\
		  ft_lstsize.c\
		  ft_lstlast.c\
		  ft_lstadd_back.c\
		  ft_lstdelone.c\
		  ft_lstclear.c\
		  ft_lstiter.c\
		  ft_lstmap.c

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else 
	OBJ_FILES = $(OBJS)
endif

SRCS	= $(SRCS_1)			\
	  $(SRCS_2)			

OBJS	= $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BN:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $<
clean :
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1

$(NAME) : $(OBJ_FILES) $(OBJS_BONUS) $(INCLUDES)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re bonus
